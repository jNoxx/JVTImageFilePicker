//
//  FilesPicker.h
//  ImagePickerMC
//
//  Created by Matan Cohen on 1/13/16.
//  Copyright © 2016 Matan Cohen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JVTImagePreviewVC.h"

@import UIKit;
@class JVTActionSheetAction;
@protocol FilesPickerDelegate <NSObject>
- (void)didPickFile:(NSData *)file
           fileName:(NSString *)fileName;
- (void)didPickImage:(UIImage *)image
       withImageName:(NSString *)imageName;
@optional
- (void)didDismissFilesPicker;
@end

@interface JVTImageFilePicker : NSObject <UIDocumentPickerDelegate, UIDocumentMenuDelegate, JVTImagePreviewVCDelegate>
@property (nonatomic,assign) CGSize imageResizeSize;
@property (assign) bool isFilePickerEnabled; // Default is YES.
@property (weak) id<FilesPickerDelegate> delegate;

// Translations
@property (nonatomic, assign) NSString *photoLibraryTxt;
@property (nonatomic, assign) NSString *takePhotoOrVideoTxt;
@property (nonatomic, assign) NSString *uploadFileTxt;
@property (nonatomic, assign) NSString *bibliotheekTxt;
@property (nonatomic, assign) NSString *cancelTxt;
@property (nonatomic, assign) NSString *kiesTxt;

- (void)presentFilesPickerOnController:(UIViewController *)presentFromController;
- (void)presentFilesPickerOnController:(UIViewController *)presentFromController
  withAddingCustomActionsToActionSheet:(NSArray<JVTActionSheetAction *> *)customAlertActions;
@end
