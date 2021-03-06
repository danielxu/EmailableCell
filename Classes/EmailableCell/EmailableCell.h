
/*
 Copyright 2011 Ahmet Ardal
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

//
//  EmailableCell.h
//  EmailableCell
//
//  Created by Ahmet Ardal on 7/3/11.
//  Copyright 2011 SpinningSphere Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol EmailableCellDelegate;

@interface EmailableCell: UITableViewCell
{
    NSString *emailAddress;
    NSString *sendEmailMenuItemTitle;
    NSIndexPath *indexPath;
    id<EmailableCellDelegate> delegate;
}

@property (nonatomic, retain) NSString *emailAddress;
@property (nonatomic, retain) NSString *sendEmailMenuItemTitle;
@property (nonatomic, retain) NSIndexPath *indexPath;
@property (nonatomic, assign) id<EmailableCellDelegate> delegate;

@end


@protocol EmailableCellDelegate<NSObject>
@required
- (void) emailableCell:(EmailableCell *)cell selectCellAtIndexPath:(NSIndexPath *)indexPath;
- (void) emailableCell:(EmailableCell *)cell deselectCellAtIndexPath:(NSIndexPath *)indexPath;

@optional
- (NSString *) emailableCell:(EmailableCell *)cell emailAddressForCellAtIndexPath:(NSIndexPath *)indexPath;
- (void) emailableCell:(EmailableCell *)cell didPressSendEmailOnCellAtIndexPath:(NSIndexPath *)indexPath;
@end
