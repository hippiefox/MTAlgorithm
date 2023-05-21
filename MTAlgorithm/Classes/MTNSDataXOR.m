//
//  MTNSDataXOR.m
//  Pods
//
//  Created by pulei yu on 2023/5/21.
//

#import "MTNSDataXOR.h"

@implementation MTNSDataXOR
+ (NSData *)doXOR:(NSData *)data{
    Byte * pointBit = (Byte *)[data bytes];
    for (long i = 0; i < data.length; i++) {
        pointBit[i] = pointBit[i] ^ 1;
    }
    return data;

}
@end
