#include "include file.cpp"

struct tower{
    vector<SDL_Texture*> arch;
    vector<SDL_Texture*> cst;
    vector<SDL_Texture*> knt;
    vector<vector<int>> index_map1;
    vector<vector<int>> index_map2;
    vector<vector<int>> index_map3;
    vector<vector<int>> spam_tower;//x,y,updown,type,level,time cooldown bullet
    vector<SDL_Texture*> status;// trang thai cua bang hien thi 

    tower (SDL_Renderer*rd,vector<SDL_Surface*> sf1 ,vector<SDL_Surface*> sf2 , vector<SDL_Surface*> sf3,vector<SDL_Surface*> sf4){
        for(int i=0;i<3;i++){
            arch.push_back(SDL_CreateTextureFromSurface(rd,sf1[i]));
            cst.push_back(SDL_CreateTextureFromSurface(rd,sf2[i]));
            knt.push_back(SDL_CreateTextureFromSurface(rd,sf3[i]));
            status.push_back(SDL_CreateTextureFromSurface(rd,sf4[i]));
        }
    }

    void get_index(const char *m1,const char *m2,const char *m3){
        ifstream read1(m1);
        ifstream read2(m2);
        ifstream read3(m3);

        for(int i=0;i<16;i++){
            int num1,num2,num3;
            for(int j=0;j<28;j++){
                read1>>num1; read2>>num2 ; read3>>num3;
                if (num1==1) index_map1.push_back({j,i,0,0,1,0});// x, y ,mode updown, status show menu ,level,type
                if (num2==1&&i==6) index_map2.push_back({j,i,1,0,1,0});
                else if(num2==1&&i!=6) index_map2.push_back({j,i,0,0,1,0});
                if (num3==1&&(i==4||i==9)) index_map3.push_back({j,i,0,0,1,0});
                else if(num3==1 && i!=4&& i!=9) index_map3.push_back({j,i,1,0,1,0});
            }
        }
        read1.close();read2.close();read3.close();
    }

    vector<vector<int>> return_index(int number){  // trả về các ô có thể thêm bớt tower
        if(number==1) return index_map1;
        else if(number==2) return index_map2;
        return index_map3;
    }

    void add_tower(int x,int y,int updown,int type,int level){
        bool mode =true;
        for(int i=0;i<spam_tower.size();i++){
            if (spam_tower[i][0]==x &&spam_tower[i][1]==y){
                mode=false;
                break;
            }
        }
        if(mode){
            int time_to_spawm_bullet=SDL_GetTicks();
            spam_tower.push_back({x,y,updown,type,level,time_to_spawm_bullet});
        }
    }
    void delete_tower(int x,int y,int& gold){
        for(int i=0;i<spam_tower.size();i++){
            if(spam_tower[i][0]==x&&spam_tower[i][1]==y){
                if(spam_tower[i][3]==1){
                    if (spam_tower[i][4]==1) gold+=50;
                    else if (spam_tower[i][4]==2) gold+=75;
                    else if (spam_tower[i][4]==3) gold+=100;
                }
                else if(spam_tower[i][3]==2){
                    if (spam_tower[i][4]==1) gold+=25;
                    else if (spam_tower[i][4]==2) gold+=40;
                    else if (spam_tower[i][4]==3) gold+=60;
                }
                else if(spam_tower[i][3]==3){
                    if (spam_tower[i][4]==1) gold+=5;
                    else if (spam_tower[i][4]==2) gold+=15;
                    else if (spam_tower[i][4]==3) gold+=40;
                }
                spam_tower.erase(spam_tower.begin()+i,spam_tower.begin()+i+1);
                break;
            }
        }
    }

    void upgrade(int x,int y,int&gold){
        for(int i=0;i<spam_tower.size();i++){
            if(spam_tower[i][0]==x&&spam_tower[i][1]==y){
                if(spam_tower[i][3]==1){
                    if (spam_tower[i][4]==1 && gold>=150){
                        gold-=150;
                        spam_tower[i][4]++;
                    }
                    else if (spam_tower[i][4]==2 && gold>=200){
                        gold-=200;
                        spam_tower[i][4]++;
                    }
                }
                else if(spam_tower[i][3]==2){
                    if (spam_tower[i][4]==1 && gold>=75){
                        gold-=75;
                        spam_tower[i][4]++;
                    }
                    else if (spam_tower[i][4]==2 && gold>=125){
                        gold-=125;
                        spam_tower[i][4]++;
                    }
                }
                else if(spam_tower[i][3]==3){
                    if (spam_tower[i][4]==1 && gold>=25){
                        gold-=25;
                        spam_tower[i][4]++;
                    }
                    else if (spam_tower[i][4]==2 && gold>=75){
                        gold-=75;
                        spam_tower[i][4]++;
                    }
                }
            }
        }
    }

    void show_tower(SDL_Renderer*rd){
        for(int i=0;i<spam_tower.size();i++){
            if(spam_tower[i][3]==1){
                SDL_Rect rect={spam_tower[i][0]*50-10,spam_tower[i][1]*50-30,70,70};
                SDL_RenderCopy(rd,arch[spam_tower[i][2]],nullptr,&rect);
            }
            else if(spam_tower[i][3]==2){
                SDL_Rect rect={spam_tower[i][0]*50-10,spam_tower[i][1]*50-30,70,70};
                SDL_RenderCopy(rd,cst[spam_tower[i][2]],nullptr,&rect);
            }
            else if(spam_tower[i][3]==3){
                SDL_Rect rect={spam_tower[i][0]*50-5,spam_tower[i][1]*50-5,60,60};
                SDL_RenderCopy(rd,knt[spam_tower[i][2]],nullptr,&rect);
            }
        }
    }
    void show_menu_select_tower(SDL_Renderer *rd,int x,int y){
        SDL_Rect rect1={x*50-75,y*50-70,60,60};
        SDL_Rect rect2={x*50-5,y*50-70,60,60};
        SDL_Rect rect3={x*50+65,y*50-70,60,60};
        SDL_RenderCopy(rd,arch[2],nullptr,&rect1);
        SDL_RenderCopy(rd,cst[2],nullptr,&rect2);
        SDL_RenderCopy(rd,knt[2],nullptr,&rect3);
    }
    void clear_tower(){
        spam_tower.clear();
    }
    void show_status_tower(SDL_Renderer * rd, int x,int y){
        SDL_Rect rect ={x*50-75,y*50-120,200,50};
        SDL_RenderCopy(rd,status[0],nullptr,&rect);
    }
    void show_sell_or_ugr(SDL_Renderer *rd,int x,int y,int lv){
        // show table
        SDL_Rect rect1={x*50-75,y*50-60,95,30};
        SDL_Rect rect2={x*50+30,y*50-60,95,30};
        SDL_Rect rect3 ={x*50-75,y*50-140,200,80};
        SDL_RenderCopy(rd,status[0],nullptr,&rect3);
        SDL_RenderCopy(rd,status[1],nullptr,&rect1);
        SDL_RenderCopy(rd,status[1],nullptr,&rect2);
        // show text
        TTF_Font *font = TTF_OpenFont("font/FiraMono-Regular.ttf",20);
        SDL_Color yellow={255,255,0,0};
        SDL_Color white={255,255,255,0};
        SDL_Color black={0,0,0,0};
        SDL_Rect idx1={x*50-50,y*50-55,45,20};
        SDL_Rect idx2={x*50+45,y*50-55,65,20};
        SDL_Surface *sell= TTF_RenderText_Blended(font,"SELL",yellow);
        SDL_Surface *ugd1= TTF_RenderText_Blended(font,"UPGRADE",white);
        SDL_Surface *ugd2= TTF_RenderText_Blended(font,"UPGRADE",black);

        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sell);
        SDL_RenderCopy(rd,tt,nullptr,&idx1);
        SDL_DestroyTexture(tt);
        if(lv<3) tt=SDL_CreateTextureFromSurface(rd,ugd1);
        else if(lv>=3) tt=SDL_CreateTextureFromSurface(rd,ugd2);
        SDL_RenderCopy(rd,tt,nullptr,&idx2);
        SDL_DestroyTexture(tt);
        
        SDL_FreeSurface(sell);SDL_FreeSurface(ugd1);SDL_FreeSurface(ugd2);
        TTF_CloseFont(font);
    }

    vector<vector<int>> index_spawmtower(){ // trả về các ô đang chứa tower
        return spam_tower;
    }

    void get_spawmtower(vector<vector<int>> arr){
        spam_tower=arr;
    }
};




struct arua{
    SDL_Texture* tt1,*tt2;
    int cut_sizex=192,cut_sizey=192;
    // size (960,384) -> 192,192
    arua(SDL_Renderer *rd,SDL_Surface *sf1,SDL_Surface *sf2){
        tt1=SDL_CreateTextureFromSurface(rd,sf1);
        tt2=SDL_CreateTextureFromSurface(rd,sf2);
    }

    void show_arua(SDL_Renderer *rd,int idx1,int idx2,int sizex,int sizey,int lv){
        SDL_Rect cut={sizex*192,sizey*192,192,192};
        SDL_Rect rect={idx1*50-35,idx2*50-40,120,120};
        if(lv==2){
            SDL_RenderCopy(rd,tt1,&cut,&rect);
        }
        else if (lv==3){
            SDL_RenderCopy(rd,tt2,&cut,&rect);
        }
    }
};