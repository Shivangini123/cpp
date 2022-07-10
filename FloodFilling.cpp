#include<iostream.h>
#include<graphics.h>
#include<dos.h>
 
void floodFill(int a,int b,int oldcolor,int newcolor){
	if(getpixel(a,b) == oldcolor){
		putpixel(a,b,newcolor);
		floodFill(a+1,b,oldcolor,newcolor);
		floodFill(a,b+1,oldcolor,newcolor);
		floodFill(a-1,b,oldcolor,newcolor);
		floodFill(a,b-1,oldcolor,newcolor);
	}
}
 
int main(){
	int gm,gd=DETECT,radius;
	int a,b;
	cout<<"Enter a and b positions for circle: "<<endl;
	cin>>x>>y;
	cout<<"Enter radius of circle"<<endl;
	cin>>radius;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	circle(a,b,radius);
	floodFill(a,b,0,15);
	delay(3000);
	closegraph();
	return 0;
}
