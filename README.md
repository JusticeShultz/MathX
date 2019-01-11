# MathX V1.20.42
![alt text](https://github.com/JusticeShultz/MathX/blob/master/ImageExamples/WEW.gif)

## MathX is a generic math library built for use of simple/commonly needed math functions that are generally used in games. This library supports dynamic operators and a wide range of different functions. Lines, curves, matrices, etc are also included for more complex functionality.

### Changelog:
Code has been cleaned up significantly.
Major change: utils.h is no longer what should be included - include "MathX.h" for full access to the entire math library in one line.
Engine type object system added.
Matrices are fully working, woohoo!

All operations are now in capital lettering format. 
The == operator now correctly handles floating point operators by only using the first few decimal places(floats lose data the more you use them so epsilon is used). 
Custom unit test functions added, the ability to check implemented types and floating point types has been added. 
Unit test now has all available tests. 
Normalize functions for Vector2, Vector3 & Vector4 now work correctly. 
Added a FLOATMIN definition to make sure floats == operations work correctly due to floating point number data loss. 
Added documentation to all functions that were missing it.
Converted ALL of the examples to use the correct capitalization method.
Fixed angle betweens redundant code.

### Deprecated as of this patch:
float lerps, 
type template lerps, 
vector2 only hermite curves, 
char color system, 
char literal system, 
char operations in colors, 
lowercase operations, 
bounders.
non templated types.


# Example Projects:

This math library features some basic visual examples of the math functions in action using a cpp library named Raylib.

### Dynamic Editable Catmull-Rom Spline Line Follower:
![alt text](https://github.com/JusticeShultz/MathLibrary/blob/master/ImageExamples/Image01.PNG)

### Simple mouse following orbiter:
![alt text](https://github.com/JusticeShultz/MathLibrary/blob/master/ImageExamples/Image02.PNG)

### Simple vector math tank:
![alt text](https://github.com/JusticeShultz/MathLibrary/blob/master/ImageExamples/Image03.PNG)

### Assassin game with a 2D "flashlight system":
![alt text](https://github.com/JusticeShultz/MathLibrary/blob/master/ImageExamples/Image04.PNG)