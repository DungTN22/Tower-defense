#include "include file.cpp"
struct chi_so{
    int gold,score,wave, tottal;

    SDL_Color cl1={255,255,0,0},cl2={255,255,255,0};

    vector<SDL_Texture*> tt;  // thanh menu, diamond, wave, skud(total), money, thanh wave

    TTF_Font *font=TTF_OpenFont("font/SuperMario256.ttf",50);

    chi_so (SDL_Renderer*rd,vector<SDL_Surface*> sf){
        for(int i=0;i<6;i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,sf[i]);
            tt.push_back(t);
        }
    }
    void update_total_gold(int golds,int tottals){
        gold=golds;
        tottal=tottals;
        wave=1;
        score=0;
    }

    void show_thanhcongcu(SDL_Renderer *rd){
        SDL_Rect thanh_hthi1={550,10,300,40};
        SDL_Rect thanh_hthi2={0,630,150,50};
        SDL_Rect thanh_hthi3={0,690,150,50};
        SDL_Rect thanh_hthi4={0,750,150,50};
        SDL_Rect diamond={0,630,40,50};
        SDL_Rect money={0,690,40,50};
        SDL_Rect total={0,750,40,50};
        SDL_RenderCopy(rd,tt[5],nullptr,&thanh_hthi1);
        SDL_RenderCopy(rd,tt[0],nullptr,&thanh_hthi2);
        SDL_RenderCopy(rd,tt[0],nullptr,&thanh_hthi3);
        SDL_RenderCopy(rd,tt[0],nullptr,&thanh_hthi4);
        SDL_RenderCopy(rd,tt[1],nullptr,&diamond);
        SDL_RenderCopy(rd,tt[4],nullptr,&money);
        SDL_RenderCopy(rd,tt[3],nullptr,&total);
    }

    void show_value(SDL_Renderer *rd){
        string str_gold = to_string(gold),str_wave = "wave " + to_string(wave),str_score = to_string(score),str_total =to_string(tottal);

        int gold_size=str_gold.size(),wave_size=str_wave.size(),total_size=str_total.size(),score_size=str_score.size(); 

        SDL_Rect i_score={55,645,10*score_size,25},i_total={55,765,10*total_size,25},i_wave={640,15,20*wave_size,40},i_gold={55,705,gold_size*10,25};

        SDL_Surface *sf1=TTF_RenderText_Blended(font,str_gold.c_str(),cl2);
        SDL_Surface *sf2=TTF_RenderText_Blended(font,str_score.c_str(),cl2);
        SDL_Surface *sf3=TTF_RenderText_Blended(font,str_total.c_str(),cl2);
        SDL_Surface *sf4=TTF_RenderText_Blended(font,str_wave.c_str(),cl1);

        SDL_Texture *tt =SDL_CreateTextureFromSurface(rd,sf1);
        SDL_RenderCopy(rd,tt,nullptr,&i_gold);
        SDL_DestroyTexture(tt);

        tt =SDL_CreateTextureFromSurface(rd,sf2);
        SDL_RenderCopy(rd,tt,nullptr,&i_score);
        SDL_DestroyTexture(tt);

        tt =SDL_CreateTextureFromSurface(rd,sf3);
        SDL_RenderCopy(rd,tt,nullptr,&i_total);
        SDL_DestroyTexture(tt);

        tt =SDL_CreateTextureFromSurface(rd,sf4);
        SDL_RenderCopy(rd,tt,nullptr,&i_wave);
        SDL_DestroyTexture(tt);

        SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
    }
    
    void show_cost_and_value(SDL_Renderer *rd,int x,int y,string name){
        SDL_Rect rect1 ={x*50-60,y*50-115,70,20};
        SDL_Rect rect2 ={x*50+35,y*50-115,70,15};
        SDL_Rect rect3 ={x*50-60,y*50-90,70,15};
        SDL_Rect rect4 ={x*50+35,y*50-90,70,15};
        if (name=="knight"){
            SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 25",cl2);
            SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 150",cl2);
            SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 10",cl2);
            SDL_Surface *sf4 =TTF_RenderText_Blended(font,name.c_str(),cl2);

            SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
            SDL_RenderCopy(rd,tt,nullptr,&rect2);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf2);
            SDL_RenderCopy(rd,tt,nullptr,&rect3);
            SDL_DestroyTexture(tt);
            
            tt=SDL_CreateTextureFromSurface(rd,sf3);
            SDL_RenderCopy(rd,tt,nullptr,&rect4);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf4);
            SDL_RenderCopy(rd,tt,nullptr,&rect1);
            SDL_DestroyTexture(tt);

            SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
        }
        else if(name=="fireball"){
            SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 90",cl2);
            SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 170",cl2);
            SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 50",cl2);
            SDL_Surface *sf4 =TTF_RenderText_Blended(font,name.c_str(),cl2);
            SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
            SDL_RenderCopy(rd,tt,nullptr,&rect2);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf2);
            SDL_RenderCopy(rd,tt,nullptr,&rect3);
            SDL_DestroyTexture(tt);
            
            tt=SDL_CreateTextureFromSurface(rd,sf3);
            SDL_RenderCopy(rd,tt,nullptr,&rect4);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf4);
            SDL_RenderCopy(rd,tt,nullptr,&rect1);
            SDL_DestroyTexture(tt);

            SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
        }
        else if(name=="arrow"){
            SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 200",cl2);
            SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 200",cl2);
            SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 100",cl2);
            SDL_Surface *sf4 =TTF_RenderText_Blended(font,name.c_str(),cl2);
            SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
            SDL_RenderCopy(rd,tt,nullptr,&rect2);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf2);
            SDL_RenderCopy(rd,tt,nullptr,&rect3);
            SDL_DestroyTexture(tt);
            
            tt=SDL_CreateTextureFromSurface(rd,sf3);
            SDL_RenderCopy(rd,tt,nullptr,&rect4);
            SDL_DestroyTexture(tt);

            tt=SDL_CreateTextureFromSurface(rd,sf4);
            SDL_RenderCopy(rd,tt,nullptr,&rect1);
            SDL_DestroyTexture(tt);

            SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
        }

    }

    void show_thongso_sell_upgrade(SDL_Renderer*rd, int x,int y,int type,int lv){
        vector<vector<int>> arr;
        SDL_Rect idx1 = {x*50-60,y*50-130,60,30};
        SDL_Rect idx2 = {x*50+10,y*50-130,100,30};
        SDL_Rect idx3 = {x*50-60,y*50-95,60,30};
        SDL_Rect idx4 = {x*50+10,y*50-95,100,30};
        if (lv==1){
            if(type==1){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 200->300",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 200->250",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 150",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 50",cl2);
                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==2){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 90->180",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 170->200",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 75",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 25",cl2);
                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==3){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 25->50",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 150->180",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 25",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 5",cl2);
                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
        }
        else if(lv==2){
             if(type==1){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 300->400",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 250->300",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 200",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 75",cl2);
                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==2){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 180->270",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 200->230",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 125",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 40",cl2);

                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==3){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 50->75",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 180->310",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"Cost 75",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 15",cl2);

                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
        }
        else if(lv==3){
             if(type==1){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 400 max",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 300 max",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 100",cl2);

                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);
                
                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==2){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 270 max",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 230 max",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 60",cl2);

                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
            else if(type==3){
                SDL_Surface *sf1 =TTF_RenderText_Blended(font,"Dame 75 max",cl2);
                SDL_Surface *sf3 =TTF_RenderText_Blended(font,"Range 210 max",cl2);
                SDL_Surface *sf2 =TTF_RenderText_Blended(font,"",cl2);
                SDL_Surface *sf4 =TTF_RenderText_Blended(font,"Sell 40",cl2);

                SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
                SDL_RenderCopy(rd,tt,nullptr,&idx2);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf2);
                SDL_RenderCopy(rd,tt,nullptr,&idx3);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf3);
                SDL_RenderCopy(rd,tt,nullptr,&idx4);
                SDL_DestroyTexture(tt);

                tt=SDL_CreateTextureFromSurface(rd,sf4);
                SDL_RenderCopy(rd,tt,nullptr,&idx1);
                SDL_DestroyTexture(tt);

                SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);
            }
        }
    }

};