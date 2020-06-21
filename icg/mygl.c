/**
 * Autores: Tiago Silva da Costa.
 *          Marcus vinicius.
 * 
 * 
 * **/
#include "mygl.h"

// Um pixel é composto por 4 bytes
struct RGBA
{
    int red;
    int green;
    int blue;
    int alpha;
 
}RGBA;
struct RGBA rgba;// = {255, 0,0, 255};

struct Pixel
{
    int x;
    int y;
}Pixel;

 struct P1
{
    int x1;
    int y1;
}P1;

 struct P2
{
    int x2;
    int y2;
}P2;

 struct DeltaX
 {
    int deltaX;    
 }DeltaX;
  struct DeltaY
 {
    int deltaY;    
 }DeltaY;
// -=--=-=pontos setados. acende um pixels no meio da tela =-=-=-/
struct Pixel pixel;//= {250,250};
struct P1 p1;
struct P2 p2;
struct DeltaX deltax;
struct DeltaY deltay;
//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno

void MyGlDraw(void) {


printPixels();

Drawline();
/* pixel da cor verde*/



 }

int pos(int x, int y){
    int l = ((y*4)*IMAGE_WIDTH); //l é linha, 4 bytes por pixel
    int c = (x*4);               //c é coluna, 4 bytes por pixel
    int position = l + c;
    return position;          
  }
  void putPixel(struct Pixel pixel, struct RGBA rgba){

//teste para que não sejam pintados pixels indevidos na tela, limitando o desenho a apenas a area //disponível



 if((pixel.x>=0 && pixel.x<IMAGE_HEIGHT) && (pixel.y>=0 && pixel.y<IMAGE_WIDTH)){


    fb_ptr[pos(pixel.x, pixel.y)+0] = rgba.red;
    fb_ptr[pos(pixel.x, pixel.y)+1] = rgba.green;
    fb_ptr[pos(pixel.x, pixel.y)+2] = rgba.blue;
    fb_ptr[pos(pixel.x, pixel.y)+3] = rgba.alpha;

      
  }

 

}


void printPixels(){

/* pixel da cor vermelha */
pixel.x = 050;
pixel.y = 184;
rgba.red = 255;
rgba.green = 0;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/* pixel da cor verde*/
pixel.x = 165;
pixel.y = 480;
rgba.red = 0;
rgba.green = 255;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/*píxel da cor azul*/
pixel.x = 300;
pixel.y = 120;
rgba.red = 0;
rgba.green = 0;
rgba.blue = 255;
rgba.alpha = 255; 
putPixel(pixel, rgba);

}

void Drawline(){
    int DELTAX = (DeltaX.deltaX = P2.x2 - P1.x1);
    int DELTAY = (DeltaY.deltaY = P2.y2 - P1.y1);
    int d = 2*DELTAY - DELTAX;
    int incE = 2 *DELTAY;
    int incNE = 2*(DELTAY - DELTAX);
    
//desenhamos 3 linhas
for(int i = 0; i <= 250;i++){
  /*desenha uma linha vermelha na diagonal de cima para baixo
  E na metade muda para verde*/
    pixel.x = i;
    pixel.y = i; //como não há parametro para o coeficiente angular a linha terá 45°

    rgba.red = 255;
    rgba.green = 0;
    rgba.blue = 0;
    rgba.alpha = 255;

    if(i >= 125){      //muda para verde
      rgba.red = 0;
      rgba.green = 0;
      rgba.blue = 255;
      rgba.alpha = 255;

    }

      putPixel(pixel, rgba);

      
}
for(int j = 0;j <= 512; j++){
  pixel.x = j;
  pixel.y = 250;

   rgba.red = 0;
   rgba.green = 255;
   rgba.blue = 0;
   rgba.alpha = 255;

   putPixel(pixel, rgba);
  
  
}

for(int i=0, j=250; i<250;i++,j--){
  
  
    pixel.x = j;
    pixel.y = i;

    rgba.red = 200;
    rgba.green = 224;
    rgba.blue = 18;
    rgba.alpha = 255;
 
    putPixel(pixel, rgba);
    }
   
}

/*void drawline(){

    int DELTAX = (DeltaX.deltaX = P2.x2 - P1.x1);
    int DELTAY = (DeltaY.deltaY = P2.y2 - P1.y1);
    int d = 2*DELTAY - DELTAX;
    int incE = 2 *DELTAY;
    int incNE = 2*(DELTAY - DELTAX);
    int x=P1.x1;
	int y=P1.y1;
    while(P2.x2<P1.x1)
    {
		if(d>=0)
		{
			putPixel(pixel,rgba);
			y=y+1;
			d=d+2*DELTAY-2*DELTAX;
		}
		else
		{
			putpixel(pixel,rgba);
			d=d+2*DELTAY;
		}
		x=x+1;
	}
}*/



