#include "include file.cpp"


// load tilemap
class tilemap{

    private: 
    int size=50;
    vector<vector<int>> map;
    vector<vector<SDL_Texture*>> tt;
    int length=28,height=16;

    public:
    void import_map(const char* number,vector<SDL_Surface*> grd,SDL_Renderer* rd){
        ifstream read(number);
        int num;
        for (int i=0;i<height;i++){
            vector<int> arr={};
            vector<SDL_Texture*> arr1={};
            for(int j=0;j<length;j++){
                read >> num;
                arr.push_back(num);
                SDL_Texture*t=SDL_CreateTextureFromSurface(rd,grd[num]);
                arr1.push_back(t);
            }   
            map.push_back(arr);
            tt.push_back(arr1);
        }
        read.close();
    }

    void export_map(SDL_Renderer* rd){
        for(int i=0;i<height;i++){
            for(int j=0;j<length;j++){
                SDL_Rect index={j*size,i*size,size,size};
                SDL_RenderCopy(rd,tt[i][j],nullptr,&index);
            }
        }
    }

};


struct extra_gui{
    vector<SDL_Texture*> tt={};
    SDL_Rect treesize={};
    SDL_Rect stumpsize={};
    SDL_Rect wellsize={};
    SDL_Rect castlesize={};
    SDL_Rect villagersize={};
    SDL_Rect graveyardsize={};

    extra_gui(SDL_Renderer*rd,vector<SDL_Surface*> sf){
        for(int i=0;i<sf.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,sf[i]);
            tt.push_back(t);
        }
    }
    void draw_extra_map1(SDL_Renderer*rd,vector<vector<int>> index){
        for(int i=0;i<index.size();i++){
            if (i==0){
                SDL_Rect castlesize={index[i][0],index[i][1],250,200};//1150,0
                SDL_RenderCopy(rd,tt[0],nullptr,&castlesize);
            }
            else if (i==1){
                SDL_Rect villagersize={index[i][0],index[i][1],150,150};//650,150
                SDL_RenderCopy(rd,tt[1],nullptr,&villagersize);
            }
            else if (i==2){
                SDL_Rect wellsize={index[i][0],index[i][1],50,50};//500,200
                SDL_RenderCopy(rd,tt[2],nullptr,&wellsize);
            }
            else if (i>=3&&i<=6){
                SDL_Rect graveyardsize={index[i][0],index[i][1],30,40};// (110,5) (110,55) (210,5) (210,55)
                SDL_RenderCopy(rd,tt[3],nullptr,&graveyardsize);
            }
            else{
                SDL_Rect treesize={index[i][0],index[i][1],60,80};
                SDL_RenderCopy(rd,tt[4],nullptr,&treesize);
            }
        }
    }
    void draw_extra_map2(SDL_Renderer*rd,vector<vector<int>> index){
        for(int i=0;i<index.size();i++){
            if (i==0){
                SDL_Rect castlesize={index[i][0],index[i][1],250,200};//1150,0
                SDL_RenderCopy(rd,tt[0],nullptr,&castlesize);
            }
            else if (i==1){
                SDL_Rect villagersize={index[i][0],index[i][1],150,150};//700,50
                SDL_RenderCopy(rd,tt[1],nullptr,&villagersize);
            }
            else if (i==2){
                SDL_Rect wellsize={index[i][0],index[i][1],50,50};//550,50
                SDL_RenderCopy(rd,tt[2],nullptr,&wellsize);
            }
            else if (i>=3&&i<=6){
                SDL_Rect graveyardsize={index[i][0],index[i][1],30,40};// (10,205) (60,205) (10,305) (60,305)
                SDL_RenderCopy(rd,tt[3],nullptr,&graveyardsize);
            }
            else{
                SDL_Rect treesize={index[i][0],index[i][1],60,80};
                SDL_RenderCopy(rd,tt[4],nullptr,&treesize);
            }
        }
    }
    void draw_extra_map3(SDL_Renderer*rd,vector<vector<int>> index){
        for(int i=0;i<index.size();i++){
            if (i==0){
                SDL_Rect castlesize={index[i][0],index[i][1],250,200};//1150,0
                SDL_RenderCopy(rd,tt[0],nullptr,&castlesize);
            }
            else if (i==1){
                SDL_Rect villagersize={index[i][0],index[i][1],150,150};//600,50
                SDL_RenderCopy(rd,tt[1],nullptr,&villagersize);
            }
            else if (i==2){
                SDL_Rect wellsize={index[i][0],index[i][1],50,50};//450,50
                SDL_RenderCopy(rd,tt[2],nullptr,&wellsize);
            }
            else if (i>=3&&i<=10){
                SDL_Rect graveyardsize={index[i][0],index[i][1],30,40};// (160,5) (160,55) (260,5) (260,55) (10,455) (60,455) (10,555) (60,555)
                SDL_RenderCopy(rd,tt[3],nullptr,&graveyardsize);
            }
            else{
                SDL_Rect treesize={index[i][0],index[i][1],60,80};
                SDL_RenderCopy(rd,tt[4],nullptr,&treesize);
            }
        }
    }
};


void show_icon_in_game(SDL_Renderer*rd,vector<SDL_Surface*> sf,int mode,int index_x){
    SDL_Texture *tt;
    SDL_Rect rect={index_x,10,40,40};
    if(mode==0){
        tt=SDL_CreateTextureFromSurface(rd,sf[0]);
        SDL_RenderCopy(rd,tt,nullptr,&rect);
    }
    else if(mode==1){
        tt=SDL_CreateTextureFromSurface(rd,sf[1]);
        SDL_RenderCopy(rd,tt,nullptr,&rect);
    }
    SDL_DestroyTexture(tt);
}
