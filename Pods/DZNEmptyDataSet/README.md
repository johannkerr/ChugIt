![Screenshots_Row1](https://raw.githubusercontent.com/dzenbot/UITableView-DataSet/master/Examples/Applications/Screenshots/Screenshots_row1.png)
![Screenshots_Row2](https://raw.githubusercontent.com/dzenbot/UITableView-DataSet/master/Examples/Applications/Screenshots/Screenshots_row2.png)
(These are real life examples, available in the sample project)

### The Empty DataSet Pattern
Most applications show lists of content (datasets), which many turn out to be empty at one point, specially for new users with blank accounts. Empty screens create confusion by not being clear about what's going on, if there is an error/bug or if the user is supposed to do something within your app to be able to consume the content.

**Empty Datasets** are helpful for:
* Avoiding white-screens and communicating to your users why the screen is empty.
* Calling to action (particularly as an onboarding process).
* Avoiding other interruptive mechanisms like showing error alerts.
* Beeing consistent and improving the user experience.
* Delivering a brand presence.


### Features
* Compatible with UITableView and UICollectionView.
* Uses KVO to observe whenever the tableview calls -reloadData.
* Gives multiple possibilities of layout and appearance, by showing an image and/or title label and/or description label and/or button.
* Uses NSAttributedString for easier appearance customisation.
* Uses auto-layout to automagically center the content to the tableview, with auto-rotation support.
* Allows tap gesture on the whole tableview bounds (useful for resigning first responder or similar actions).
* Background color customisation.
* For more advanced customisation, it accepts a custom view.
* iPhone (3.5" & 4") and iPad support. iOS7 compatible only.
* ARC & 64bits support.
* **App Store ready**

This library has been designed in a way where you won't need to extend UITableView or UICollectionView class. It will still work when using UITableViewController or UICollectionViewController.
By simply conforming by just conforming to DZNEmptyDataSetSource & DZNEmptyDataSetDelegate, you will be able to fully customize the content and appearance of the empty datasets for your application.

If you are using DZNEmptyDataSet in your application, [please take a screenshot of your empty dataset render and submit it here](https://github.com/dzenbot/DZNEmptyDataSet/issues/4).


## Installation

Available in [Cocoa Pods](http://cocoapods.org/?q=DZNEmptyDataSet)
```
pod 'DZNEmptyDataSet'
```


## How to use
For complete documentation, [visit CocoaPods' auto-generated doc](http://cocoadocs.org/docsets/DZNEmptyDataSet/)

### Step 1: Import
```
#import "UIScrollView+EmptyDataSet.h"
```

### Step 2: Protocol Conformance
Conform to datasource and/or delegate.
```
@interface MainViewController : UITableViewController <DZNEmptyDataSetSource, DZNEmptyDataSetDelegate>

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.tableView.emptyDataSetSource = self;
    self.tableView.emptyDataSetDelegate = self;
}
```

### Step 3: Data Source Implementation
Return the content you want to show on the empty datasets, and take advantage of NSAttributedString features to customise the text appearance.

The title of the empty dataset:
```
- (NSAttributedString *)titleForEmptyDataSet:(UIScrollView *)scrollView {

    NSString *text = @"Please Allow Photo Access";
    
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:18.0],
                                 NSForegroundColorAttributeName: [UIColor darkGrayColor]};
    
    return [[NSAttributedString alloc] initWithString:text attributes:attributes];
}
```

The description of the empty dataset:
```
- (NSAttributedString *)descriptionForEmptyDataSet:(UIScrollView *)scrollView {

    NSString *text = @"This allows you to share photos from your library and save photos to your camera roll.";
    
    NSMutableParagraphStyle *paragraph = [NSMutableParagraphStyle new];
    paragraph.lineBreakMode = NSLineBreakByWordWrapping;
    paragraph.alignment = NSTextAlignmentCenter;
    
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:14.0],
                                 NSForegroundColorAttributeName: [UIColor lightGrayColor],
                                 NSParagraphStyleAttributeName: paragraph};
                                 
    return [[NSAttributedString alloc] initWithString:text attributes:attributes];                      
}
```

The title to be used for the specified button state:
```
- (NSAttributedString *)buttonTitleForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state {

    NSDictionary *attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:17.0]

    return [[NSAttributedString alloc] initWithString:@"Continue" attributes:attributes];
}
```

The image for the empty dataset:
```
- (UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView
{
    return [UIImage imageNamed:@"empty_placeholder"];
}
```

The background color for the empty dataset:
```
- (UIColor *)backgroundColorForEmptyDataSet:(UIScrollView *)scrollView
{
    return [UIColor whiteColor];
}
```

You can also return a custom view if your layout requieres much more appearance flexibility:
```
- (UIView *)customViewForTableViewDataSet:(UITableView *)tableView
{
    UIActivityIndicatorView *activityView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [activityView startAnimating];
    return activityView;
}
```


### Step 4: Delegate Implementation
Return the behaviours you would expect from the empty datasets, and receive the user events.

Asks for interaction permission (Default is YES) :
```
- (BOOL)emptyDataSetShouldAllowTouch:(UIScrollView *)scrollView {
    return YES;
}
```

Asks for scrolling permission (Default is NO) :
```
- (BOOL)emptyDataSetShouldAllowScroll:(UIScrollView *)scrollView {
    return YES;
}
```

Notifies when the dataset view was tapped:
```
- (void)emptyDataSetDidTapView:(UIScrollView *)scrollView {
    
}
```

Notifies when the dataset call to action button was tapped:
```
- (void)emptyDataSetDidTapButton:(UIScrollView *)scrollView {
    
}
```

### Step 5: Deallocation
It is (extremely) **important** to set the dataSetSource and dataSetDelegate to nil, whenever the view is going to be released. This class uses KVO under the hood, so it needs to remove the observer before dealocating the view..

```
- (void)dealloc
{
    self.tableView.emptyDataSetSource = nil;
    self.tableView.emptyDataSetDelegate = nil;
}
```


## Sample projects

#### Applications
This project replicates several popular application's empty datasets (~20) with their exact content and appearance, such as Airbnb, Dropbox, Facebook, Foursquare, and many others. See how easy and flexible it is to customize the appearance of your empty datasets.

#### Countries
This project shows a list of the world countries loaded from CoreData. It uses NSFecthedResultController results, for filtering search. Whenever no content is matched when searching, a simple empty dataset is shown. See how to interact between the UITableViewDataSource and the DZNEmptyDataSetSource protocols, while using a typical CoreData stack.

#### Colors
This project is a simple example of how this library also works with UICollectionView.


## Collaboration
Feel free to collaborate with ideas, issues and/or pull requests.


## License
(The MIT License)

Copyright (c) 2014 Ignacio Romero Zurbuchen <iromero@dzen.cl>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
