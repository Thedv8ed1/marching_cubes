#include "application.h"
#include <fstream>
void circle();
void Etable();
void Ttable();
void T2();

int main(int argc, char* argv[])
{
    T2();
    circle();
    Etable();
    //Ttable();
  //  return 0;
    int width = 640;
    int height = 480;

    application app;
    app.init(argc, argv, width, height);
    if(argc == 2)
        app.load_grid(argv[1]);
    app.run();
}


void circle(){
    std::fstream file;

    file.open("circle.txt",std::fstream::out);
    file << "# Dimentions are for points NOT CUBES\n" <<
    "# width 20\n"<<"# height 20\n"<<"# depth 20\n";
    int constant = 5;
    for(int x = 0; x < 20; x++){
        for(int y = 0; y < 20; y++){
            for(int z = 0; z < 20; z++){
                file << x << " ";
                file << y << " ";
                file << z << " ";
                file << (x-constant)*(x-constant)+(y-constant)*(y-constant)+(z-constant)*(z-constant)-25;
                file << std::endl;
            }   
        }      
    }
    file.close();
}

void Etable(){
    std::fstream file;
    file.open("table.txt",std::fstream::out);
    for(int i = 0; i< 256; i++){
        int edges= 0;
        if((i&1)){//v0
            if((i&2)==0){edges += 1; } // if not v1 set e0
            if((i&8)==0){edges += 8;} // if not v3 set ee3
            if((i&16)==0){edges += 256;} // if not v4 set e8
        }
        if(i&2){//v1
            if((i&1)==0){edges += 1;} // if not v0 set e0
            if((i&4)==0){edges += 2;} // if  not v2 set e1
            if((i&32)==0){edges += 512;} // if not v5 set e9
        }
        if(i&4 ){//v2
            if((i&2)==0){edges += 2;} // if not v1 set e1
            if((i&8)==0){edges += 4;} // if not v3 set e2
            if((i&64)==0){edges += 1024;} // if not v6 set e10
        }
        if(i&8 ){//v3
            if((i&1)==0){edges += 8;} // if not v0 set e3
            if((i&4)==0){edges += 4;} // if not v2 set e2
            if((i&128)==0){edges += 2048;} // if not v7 set e11
        }
        if(i&16 ){//v4
            if((i&1)==0){edges += 256;} // if not v0 set e8
            if((i&32)==0){edges += 16;} // if not v5 set e4
            if((i&128)==0){edges += 128;} // if not v7 set e7
        }
        if(i&32){//v5
            if((i&2)==0){edges += 512;} // if not v1 set e9
            if((i&16)==0){edges += 16;} // if not v4 set e4
            if((i&64)==0){edges += 32;} // if not v6 set e5
        }
        if(i&64 ){//v6
            if((i&4)==0){edges += 1024;} // if not v2 set e10
            if((i&32)==0){edges += 32;} // if not v5 set e5
            if((i&128)==0){edges += 64;} // if not v7 set e6
        }
        if(i&128){//v7
            if((i&8)==0){edges += 2048;} // if not v3 set e11
            if((i&16)==0){edges += 128;} // if not v4 set e7
            if((i&64)==0){edges += 64;} // if not v6 set e6
        }
        file << edges << ", ";
        if(i>0 && i%16 == 0){file << std::endl;}
        //file << edges << " ";
    }
    file.close();

}

void Ttable(){
    std::fstream fileIN;
    fileIN.open("table.txt",std::fstream::in);

    std::fstream fileOUT;
    fileOUT.open("table2.txt",std::fstream::out);

    int i = 0;    
    while(!fileIN.eof()){

    }


    fileIN.close();
    fileOUT.close();

}

// (n mod 3) +1?


void T2(){
      std::fstream file;

    file.open("nope.txt",std::fstream::out);
    file << "# Dimentions are for points NOT CUBES\n" <<
    "# width 16\n"<<"# height 16\n"<<"# depth 1\n";
    int constant = 5;
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            for(int z = 0; z < 1; z++){
                //file << x << " ";
                //file << y << " ";
                //file << z << " ";
                //file << (x-constant)*(x-constant)+(y-constant)*(y-constant)+(z-constant)*(z-constant)-25;
                //file << std::endl;
            }   
        }      
    }/*
    0 0 0 -1
    1 0 0 1
    1 0 1 1
    0 0 1 1

    0 1 0 1
    1 1 0 1
    1 1 1 1
    0 1 1 1
    */
    file.close();
}