//
//  ViewController.h
//  DMC_Control
//
//  Created by Jeff Kunzelman on 3/28/15.
//  Copyright (c) 2015 HardwareWeekend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Relayr/Relayr.h>
@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *fluxCapacitorTempLabel;
@property (weak, nonatomic) IBOutlet UILabel *xGeeLabel;
@property (weak, nonatomic) IBOutlet UILabel *yGeeLabel;
@property (weak, nonatomic) IBOutlet UILabel *zGeeLabel;

@end

