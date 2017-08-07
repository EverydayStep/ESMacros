//
//  ViewController.m
//  ESMacros
//
//  Created by codeLocker on 2017/7/25.
//  Copyright © 2017年 codeLocker. All rights reserved.
//

#import "ViewController.h"
#import "ESMacros.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    ES_Perform_Time_Start
    for (NSInteger i = 0; i < 10000; i++) {
        NSLog(@"aaaa");
    }
    ES_Perform_Time_End
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
