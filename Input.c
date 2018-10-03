#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
struct Player_Input {
    char type1; //*
    char type2; //#
    int row;;
    int column;
    char *filename;
} player_Input;
int main(int argc, char** argv) {
    //input filename type1(int) type2(int) r c
    player_Input.filename = malloc(sizeof(char));
    for (int i = 0; i < strlen(argv[1]); ++i) {
        player_Input.filename[i] = argv[1][i];
    }
    player_Input.type1 = argv[2][0];
    player_Input.type2 = argv[3][0];
    player_Input.row = atoi(argv[4]);
    player_Input.column = atoi(argv[5]);
    printf("%s %c %c %d %d\n", player_Input.filename, player_Input.type1,
    player_Input.type2, player_Input.row, player_Input.column);
   FILE* testfile = fopen(player_Input.filename, "r");
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

