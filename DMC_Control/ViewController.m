//
//  ViewController.m
//  DMC_Control
//
//  Created by Jeff Kunzelman on 3/28/15.
//appId=f920844d-92d8-491c-9e7e-6893cf738c9f
// client UnWtINT.nOofLY1aT6133JGzeYB2sr7N
//clientSecret=bMa3K6w8o81pMlIfotN2gJLBYzrjVE1P
//redirectUri=http://localhost

#import "ViewController.h"

#define RelayrAppID         @"f920844d-92d8-491c-9e7e-6893cf738c9f"
#define RelayrAppSecret     @"bMa3K6w8o81pMlIfotN2gJLBYzrjVE1P"
#define RelayrRedirectURI   @"http://localhost"

@interface ViewController ()


@property (nonatomic,strong) RelayrApp *relayerApp;
@property (nonatomic,strong) RelayrUser *user;
@property (nonatomic,strong) UIFont *ledFont;

//@property (nonatomic,strong) NSNumber *fluxCapaciterTemp;


@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
 
    [RelayrCloud isReachable:^(NSError* error, NSNumber* isReachable){
        if (isReachable.boolValue) {
            NSLog(@"The Relayr Cloud is reachable!");
            [self connectToRelayr];
        }
    }];
    
    NSLog(@"%@",[UIFont familyNames]);
    
    self.ledFont = [UIFont fontWithName:@"Digital-7" size:32.0];
}

-(void)connectToRelayr
{
    [RelayrApp appWithID:RelayrAppID OAuthClientSecret:RelayrAppSecret redirectURI:RelayrRedirectURI completion:^(NSError* error, RelayrApp* app){
        if (app)
        {
            NSLog(@"Application with name: %@ and description: %@",app.name, app.description);
            self.relayerApp = app;
            [self.relayerApp signInUser:^(NSError* error, RelayrUser* user){
                if (user) {
                    NSLog(@"User logged with name: %@ and email: %@", user.name, user.email);
                    _user = user;
                    
                    [self setupTransmittersAndDevices];
                }
            }];
        }
    }];
}

-(void)setupTransmittersAndDevices
{
  //   Lets ask the platform for all the transmitters/devices own by this specific user.
    [self.user queryCloudForIoTs:^(NSError* error){
        if (error) { return NSLog(@"%@", error.localizedDescription); }
        
        for (RelayrTransmitter* transmitter in self.user.transmitters)
        {
            NSLog(@"Transmitter's name: %@", transmitter.name);
            
            
        }
        
        RelayrTransmitter* transmitter = self.user.transmitters.anyObject;
        
        NSLog(@"This transmitter relays information of %lu devices", transmitter.devices.count);
        for (RelayrDevice* device in transmitter.devices)
        {
            NSLog(@"Device's name: %@", device.name);
            NSLog(@"Device manufacturer: %@ and model name: %@", device.manufacturer, device.modelName);

            NSLog(@"Device name: %@, capable of measuring %lu different values", device.name, device.readings.count);
            
            for (RelayrReading* reading in device.readings)
            {
                NSLog(@"This device can measure %@ in %@ units", reading.meaning, reading.unit);
                NSLog(@"Last value obtained by this device for this specific reading is %@ at %@", reading.value, reading.date);
                
                [reading subscribeWithTarget:self action:@selector(dataReceivedFrom:) error:^(NSError* error){
                    NSLog(@"An error occurred while subscribing");
                }];
            }
        }
    }];
}

- (void)dataReceivedFrom:(RelayrReading*)reading
{
 //   NSLog(@"Value received: %@", reading.value);
    
    NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc]init];
    [numberFormatter setPositiveFormat:@"###0.##"];
    [numberFormatter setNegativeFormat:@"-###0.##"];
    
    if ([reading.meaning isEqualToString:@"temperature"])
    {
        [self loadFluxCapacitorfrom:reading];
        self.fluxCapacitorTempLabel.text = [numberFormatter stringFromNumber:self.fluxCapacitorTemp];
    }
    
    if ([reading.meaning isEqualToString:@"acceleration"])
    {
        [self loadAccelerationDatafromReading:reading];
        self.xGeeLabel.font = self.ledFont;
        self.xGeeLabel.text = [NSString stringWithFormat:@"%@ G",[numberFormatter stringFromNumber:self.xGforce]];
        self.yGeeLabel.text = [NSString stringWithFormat:@"%@ G",[numberFormatter stringFromNumber:self.yGforce]];
        self.zGeeLabel.text = [NSString stringWithFormat:@"%@ G",[numberFormatter stringFromNumber:self.zGforce]];
    }
    
    if ([reading.meaning isEqualToString:@"proximity"])
    {
        NSLog(@"prox: %@",reading.value);
        
        self.acceleratorLabel.text = [NSString stringWithFormat:@"%@",reading.value];
    }
}

-(void)loadFluxCapacitorfrom:(RelayrReading *)reading
{
    NSString *tempString = [NSString stringWithFormat:@"%@",reading.value];
    self.fluxCapacitorTemp = [NSNumber numberWithDouble:[tempString doubleValue]];
}

-(void)loadAccelerationDatafromReading:(RelayrReading *)reading
{
    NSArray *gValues = reading.value;
    
    //   NSLog (@"G's %@",gValues);

    //arrays can't contain primitive types so we need to get it out of the array as a string and then convert it back to a double
    NSString *xGeeString = [NSString stringWithFormat:@"%@",[gValues objectAtIndex:0]];
    self.xGforce = [NSNumber numberWithDouble:[xGeeString doubleValue]];
    
    NSString *yGeeString = [NSString stringWithFormat:@"%@",[gValues objectAtIndex:1]];
    self.yGforce = [NSNumber numberWithDouble:[yGeeString doubleValue]];
    
    NSString *zGeeString = [NSString stringWithFormat:@"%@",[gValues objectAtIndex:2]];
    self.zGforce = [NSNumber numberWithDouble:[zGeeString doubleValue]];
    
    NSComparisonResult xResult = [self.xGforce compare:self.xGforceMax];
    NSComparisonResult yResult = [self.yGforce compare:self.yGforceMax];
    NSComparisonResult zResult = [self.zGforce compare:self.zGforceMax];
    
    NSComparisonResult xMaxResult = [self.xGforce compare:self.maxGforce];
    NSComparisonResult yMaxResult = [self.yGforce compare:self.maxGforce];
    NSComparisonResult zMaxResult = [self.zGforce compare:self.maxGforce];
    
    //max
    if (xResult == NSOrderedDescending)
    {
        self.xGforceMax = self.xGforce;
    }
    
    if (yResult == NSOrderedDescending)
    {
        self.yGforceMax = self.yGforce;
    }
    if (zResult == NSOrderedDescending)
    {
        self.zGforceMax = self.zGforce;
    }
    
    //Set all time max
    if (xMaxResult == NSOrderedDescending)
    {
        self.maxGforce = self.xGforce;
    }
    
    if (yMaxResult == NSOrderedDescending)
    {
        self.maxGforce = self.yGforce;
    }
    if (zMaxResult == NSOrderedDescending)
    {
        self.maxGforce = self.zGforce;
    }
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
