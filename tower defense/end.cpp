#include "include file.cpp"
struct endgame{
    vector<SDL_Texture*> tt={};//text_over,table_over,sword_over,silk_over,diamonds,moneys,background_entering,ok button
    int diamond=0;
    int score=0;
    int last=SDL_GetTicks();
    TTF_Font *font1 =TTF_OpenFont("font/FiraMono-Regular.ttf",50);
    TTF_Font *font2 =TTF_OpenFont("font/SuperMario256.ttf",50);
    SDL_Color white={255,255,255,0};
    SDL_Color yellow={255,240,0,0};

    int size_x_num=25,size_y_num=45,idx_x_name=700,idx_y_name=260,size_x_name=24,size_y_name=60;
    
    endgame(SDL_Renderer*rd,vector<SDL_Surface*> sf){
        for(int i=0;i<8;i++){
            tt.push_back(SDL_CreateTextureFromSurface(rd,sf[i]));
        }
    }

    void show_text_gameover(SDL_Renderer *rd,bool &mode1,bool &mode2){
        int now=SDL_GetTicks();
        SDL_Rect idx={400,300,600,150};
        SDL_RenderCopy(rd,tt[0],nullptr,&idx);
        if(now-last>=7000){
            mode1=true,mode2=false;
        }
    }

    void show_table_score(SDL_Renderer *rd){
        SDL_Rect idx_bg={0,0,1400,800};
        SDL_Rect idx_table={400,150,600,500};
        SDL_Rect idx_sword={550,50,300,200};
        SDL_Rect idx_silk={400,135,600,100};
        SDL_Rect idx_diamond={580,385,60,60};
        SDL_Rect idx_money={580,475,55,60};
        SDL_Rect idx_ok={575,560,250,100};
        SDL_Rect idx_text={600,160,200,60};

        SDL_RenderCopy(rd,tt[6],nullptr,&idx_bg);
        SDL_RenderCopy(rd,tt[2],nullptr,&idx_sword);
        SDL_RenderCopy(rd,tt[1],nullptr,&idx_table);
        SDL_RenderCopy(rd,tt[3],nullptr,&idx_silk);
        SDL_RenderCopy(rd,tt[4],nullptr,&idx_diamond);
        SDL_RenderCopy(rd,tt[5],nullptr,&idx_money);
        SDL_RenderCopy(rd,tt[7],nullptr,&idx_ok);

        SDL_Surface *sf=TTF_RenderText_Blended(font2,"TOTAL",yellow);
        SDL_Texture *tt= SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&idx_text);
        SDL_FreeSurface(sf);
        SDL_DestroyTexture(tt);

    }

    void show_score_gold_name(SDL_Renderer*rd,int a,int b,string name){
        score+=2;diamond+=2;
        if(diamond>b) diamond=b;
        if(score>a) score=a;
        string sc=to_string(score),da=to_string(diamond);
        int d1=idx_x_name-12*name.size(),d2=size_x_name*name.size(),d3=size_x_num*sc.size(),d4=size_x_num*da.size();
        SDL_Rect idxname={d1,idx_y_name,d2,size_y_name};
        SDL_Rect idxscore={660,392,d3,size_y_num};
        SDL_Rect idxdiamond={660,485,d4,size_y_num};

        SDL_Surface *sf1=TTF_RenderText_Blended(font1,name.c_str(),white);
        SDL_Surface *sf2=TTF_RenderText_Blended(font1,sc.c_str(),white);
        SDL_Surface *sf3=TTF_RenderText_Blended(font1,da.c_str(),white);

        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
        SDL_RenderCopy(rd,tt,nullptr,&idxname);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf2);
        SDL_RenderCopy(rd,tt,nullptr,&idxscore);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf3);
        SDL_RenderCopy(rd,tt,nullptr,&idxdiamond);
        SDL_DestroyTexture(tt);

        SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);

    }

    void clear_all(){
        diamond=0;score=0;last=SDL_GetTicks();
    }
};