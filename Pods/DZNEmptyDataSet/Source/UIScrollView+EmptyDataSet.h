//
//  UIScrollView+EmptyDataSet.h
//  DZNEmptyDataSet
//  https://github.com/dzenbot/DZNEmptyDataSet
//
//  Created by Ignacio Romero Zurbuchen on 6/20/14.
//  Copyright (c) 2014 DZN Labs. All rights reserved.
//  Licence: MIT-Licence
//

#import <UIKit/UIKit.h>

@protocol DZNEmptyDataSetSource;
@protocol DZNEmptyDataSetDelegate;

/**
 A drop-in UITableView/UICollectionView superclass category for showing empty datasets whenever the view has no content to display.
 
 @discussion It will work automatically, by just conforming to DZNEmptyDataSetSource, and returning the data you want to show. The -reloadData call will be observed so the empty dataset will be configured whenever needed. It is (extremely) important to set the dataSetSource and dataSetDelegate to nil, whenever the view is going to be released. This class uses KVO under the hood, so it needs to remove the observer before dealocating the view.
 */
@interface UIScrollView (EmptyDataSet)

/** The empty datasets data source. */
@property (nonatomic, weak) id <DZNEmptyDataSetSource> emptyDataSetSource;
/** The empty datasets delegate. */
@property (nonatomic, weak) id <DZNEmptyDataSetDelegate> emptyDataSetDelegate;
/** YES if any empty dataset is visible. */
@property (nonatomic, readonly, getter = isEmptyDataSetVisible) BOOL emptyDataSetVisible;

/**
 Call this methods whenever you want to force the data set update, whitout having to depend on the -reloadData selector.
 
 @discussion This will update the content of the controls and their constraints. If the content hasn't change, this will take no effect.
 */
- (void)reloadDataSetIfNeeded;

@end


/**
 The object that acts as the data source of the empty datasets.
 
 @discussion The data source must adopt the DZNEmptyDataSetSource protocol. The data source is not retained. All data source methods are optional. They will not be considered in the layout if they either return nil or the view controller doesn't conform to them.
 */
@protocol DZNEmptyDataSetSource <NSObject>
@required

@optional

/**
 Asks the data source for the title of the dataset.
 The dataset uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 
 @param scrollView A scrollView subclass informing the data source.
 @return An attributed string for the dataset title, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)titleForEmptyDataSet:(UIScrollView *)scrollView;

/**
 Asks the data source for the description of the dataset.
 The dataset uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 
 @param scrollView A scrollView subclass informing the data source.
 @return An attributed string for the dataset description text, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)descriptionForEmptyDataSet:(UIScrollView *)scrollView;

/**
 Asks the data source for the image of the dataset.
 
 @param scrollView A scrollView subclass informing the data source.
 @return An image for the dataset.
 */
- (UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView;

/**
 Asks the data source for the title to be used for the specified button state.
 The dataset uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 
 @param scrollView A scrollView subclass object informing the data source.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 @return An attributed string for the dataset button title, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)buttonTitleForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state;

/**
 Asks the data source for a background image to be used for the specified button state.
 There is no default style for this call.
 
 @param scrollView A scrollView subclass informing the data source.
 @param state The state that uses the specified image. The values are described in UIControlState.
 @return An attributed string for the dataset button title, combining font, text color, text pararaph style, etc.
 */
- (UIImage *)buttonBackgroundImageForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state;

/**
 Asks the data source for the background color of the dataset. Default is clear color.
 
 @param scrollView A scrollView subclass object informing the data source.
 @return An color to be applied to the dataset background view.
 */
- (UIColor *)backgroundColorForEmptyDataSet:(UIScrollView *)scrollView;

/**
 Asks the data source for a custom vertical space. Default is 11 pts.
 
 @param scrollView A scrollView subclass object informing the delegate.
 @return The space height between elements.
 */
- (CGFloat)spaceHeightForEmptyDataSet:(UIScrollView *)scrollView;

/**
 Asks the data source for a custom view to be displayed instead of the default views such as labels, imageview and button. Default is nil.
 Use this method to show an activity view indicator for loading feedback, or for complete custom empty data set.
 
 @param scrollView A scrollView subclass object informing the delegate.
 @return The custom view.
 */
- (UIView *)customViewForEmptyDataSet:(UIScrollView *)scrollView;

@end


/**
 The object that acts as the delegate of the empty datasets.
 The delegate must adopt the DZNEmptyDataSetDelegate protocol. The delegate is not retained.
 
 @discussion All delegate methods are optional. Use this delegate for receiving action callbacks.
 */
@protocol DZNEmptyDataSetDelegate <NSObject>
@required
@optional

/**
 Asks the delegate for touch permission. Default is YES.
 
 @param scrollView A scrollView subclass object informing the delegate.
 @return YES if the dataset receives touch gestures.
 */
- (BOOL)emptyDataSetShouldAllowTouch:(UIScrollView *)scrollView;

/**
 Asks the delegate for scroll permission. Default is NO.
 
 @param scrollView A scrollView subclass object informing the delegate.
 @return YES if the dataset is allowed to be scrollable.
 */
- (BOOL)emptyDataSetShouldAllowScroll:(UIScrollView *)scrollView;

/**
 Tells the delegate that the dataset view was tapped.
 Use this method either to resignFirstResponder of a textfield or searchBar.
 
 @param scrollView A scrollView subclass informing the delegate.
 */
- (void)emptyDataSetDidTapView:(UIScrollView *)scrollView;

/**
 Tells the delegate that the option button was tapped.
 
 @param scrollView A scrollView subclass informing the delegate.
 */
- (void)emptyDataSetDidTapButton:(UIScrollView *)scrollView;

@end
