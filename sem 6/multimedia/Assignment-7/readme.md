PROCEDURE TO CREATE AN ANIMATED CURSORUSING STARTDRAG("SS", TRUE); MOUSE.HIDE();

1. Go to start->Macro Media-click on Flash document
2. Insert or draw any object of your choice for example butterfly in this example.
3. Using free transform tool select the object-right click-convert to symbol- selectmovie clip- give the name(mm)- click ok.
4. Enter the instance name as (mm) using the property tool box.(same as the movie clip name).
5. Select the object using free transform tool- go to modify-> timeline->distribute to layers.
6. Select layer1 and rename it to Action
7. Select the first key frame in the action layer- go to windows- click action.
8. You will get action frame- enter the following code in the action frame.
    Mouse.hide();
    this.mm.onEnterFrame=function() {
    startDrag(this,true);
    };
9. To run the animation go to control-> movie clip. OUTPUT
