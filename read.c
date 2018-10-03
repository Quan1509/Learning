#include <stdio.h>
#include <stdlib.h>
#include </home/quan/Ass1_CSSE2310/function.h>

struct Data {
	char* data_file;
	int size;} data;
struct Shapes {
	char shapes[30];
	char tiles[5][6];
	char tiles90[5][6];
	char tiles180[5][6];
	char tiles270[5][6];
};
struct Data read_line (FILE* file)
{
	data.data_file = malloc(sizeof(char) * 320);
	data.size = 0;
	while(1) {
		int next = fgetc(file);
		if (next == EOF){
			data.data_file[data.size] = '\n';
            		//printf("%d/n", position);
		//	printf("%s", result);
			return data;}
		//else if (data.data_file[data.size] == '\n'){
		//	printf("bingo");
		//	return data;}
   		 else {
		data.data_file[data.size++] = (char)next;
		}}
	}
int N_shapes (int size){
	return size/30;
}
void turn_tiles (char x[30], char z[5][6]) {
	int g = 0;
	char *y;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 6; j++){
		    if (x[g] == '\n' || x[g] == '\0'){
			z[i][j] = '\0';
			g = g + 1;
			break;}
		    else{
			y = &x[g];
			z[i][j] = *y;
			g++;}
		}
	}
}
/*param: char x, y == Shapes.tiles; r == rotation
 *return void
 *rotate rotate tiles x and copy into y, x remain stable
 */
void rotation (char x[5][6], char y[5][6], int r){ //r==180
    char* c;
    if ( r == 180){
      for (int i = 0; i < 5; i++){
	 for (int j = 0; j < 5; j++){
	    c = &x[i][4-j];
	    y[4-i][j] = *c;
	 }
	 y[i][5] = '\0';
      }
    }else if (r == 90){
      for (int i = 0; i<5; i++){
	  for (int j = 0; j < 5; j++){
	     c = &x[j][i];
	     y[i][4-j] = *c;
	  }
       } for (int k = 0; k <5; k++){
	      y[k][5] = '\0';}
    } else if (r == 270) {
       for (int i = 0; i<5; i++){
	  for (int j = 0; j < 5; j++){
	     c = &x[j][i];
	     y[4-i][j] = *c;
	  }
       } for (int k = 0; k <5; k++){
	      y[k][5] = '\0';}
     } else if ( r == 0){
	for (int i = 0; i<5; i++){
	  for (int j = 0; j < 5; j++){
	     c = &x[i][j];
	     y[i][j] = *c;
	  }
        }
      } else {printf("error");}
}

void shapes_rotate (struct Shapes s){
	rotation (s.tiles, s.tiles90, 90);
	rotation (s.tiles, s.tiles180, 180);
	rotation (s.tiles, s.tiles270, 270);
}/*
int main (int argc, char** argv){
   FILE* testfile = fopen("ft", "r");
   if (testfile == NULL) {
      printf("wtf \n");
   }
   read_line(testfile);
   int s = N_shapes(data.size);
   int z = 0;
   struct Shapes se[s];
   for (int i = 0; i < s; i++){
	for (int j = 0; j < 30; j++){
	    if (data.data_file[z] == '\n' && data.data_file[z] == data.data_file[z+1]){
		se[i].shapes[j] = '\0';
		z = z+2;
		break;}
	    else {
		se[i].shapes[j] = data.data_file[z];
		z++;}
	}
   }
   free(data.data_file);
for (int ui =0; ui<s; ui ++){
   turn_tiles(se[ui].shapes, se[ui].tiles);
   rotation (se[ui].tiles, se[ui].tiles90, 90);
   rotation (se[ui].tiles, se[ui].tiles180, 180);
   rotation (se[ui].tiles, se[ui].tiles270, 270);
   for (int c = 0; c<5; c++) {
	printf("%s %s %s %s", se[ui].tiles[c], se[ui].tiles90[c], se[ui].tiles180[c], se[ui].tiles270[c]);
	printf("\n");} printf("\n");
}
//printf("%s %s %s %s", se[0].tiles[0], se[0].tiles90[0], se[0].tiles180[0], se[0].tiles270[0]);
   return 0;
}
*/

