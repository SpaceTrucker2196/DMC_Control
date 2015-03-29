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

@property (nonatomic,strong) NSNumber *fluxCapaciterTemp;


@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [RelayrCloud isReachable:^(NSError* error, NSNumber* isReachable){
        if (isReachable.boolValue) {
            NSLog(@"The Relayr Cloud is reachable!");
        }
    }];
    
    
    [RelayrApp appWithID:RelayrAppID OAuthClientSecret:RelayrAppSecret redirectURI:RelayrRedirectURI completion:^(NSError* error, RelayrApp* app){
        if (app)
        {
            NSLog(@"Application with name: %@ and description: %@",app.name, app.description);
            self.relayerApp = app;
            [self.relayerApp signInUser:^(NSError* error, RelayrUser* user){
                if (user) {
                    NSLog(@"User logged with name: %@ and email: %@", user.name, user.email);
                    _user = user;
                    
                    [self relayerTransmitters];
                }
            }];
        }
    }];
   
}


-(void)relayerTransmitters
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
//
    
}

- (void)dataReceivedFrom:(RelayrReading*)reading
{
    NSLog(@"Value received: %@", reading.value);
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
