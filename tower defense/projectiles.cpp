#include "include file.cpp"


struct bullet {
    SDL_Texture* rok;
    vector<SDL_Texture*> fball1 ,fball2, fball3;
    vector<SDL_Texture*> arow1 ,arow2 ,arow3;
    vector<vector<int>> status_towers;//x,y,updown,type,level,time cooldown bullet
    vector<vector<int>> status_enermy;// index_x,index_y,change_x,change_y,type,mode img,time_to_change_img,hp
    vector<vector<int>> bullets; // indx_x,idx_y,type,number of aim,lv,num of pic
    vector<int> angle;
    int vantocr=6,vantocf=7,vantoca=8;
    int r_rock=150,r_arow=170,r_fireball=200;


    bullet (SDL_Renderer*rd,SDL_Surface* sfrok,vector<SDL_Surface*> sfb1,vector<SDL_Surface*> sfb2,vector<SDL_Surface*> sfb3,vector<SDL_Surface*> sfa1,vector<SDL_Surface*> sfa2,vector<SDL_Surface*> sfa3){
        rok=SDL_CreateTextureFromSurface(rd,sfrok);
        for(int i=0;i<sfb1.size();i++){
            fball1.push_back(SDL_CreateTextureFromSurface(rd,sfb1[i]));
            fball2.push_back(SDL_CreateTextureFromSurface(rd,sfb2[i]));
            fball3.push_back(SDL_CreateTextureFromSurface(rd,sfb3[i]));
        }
        for(int i=0;i<sfa1.size();i++){
            arow1.push_back(SDL_CreateTextureFromSurface(rd,sfa1[i]));
            arow2.push_back(SDL_CreateTextureFromSurface(rd,sfa2[i]));
            arow3.push_back(SDL_CreateTextureFromSurface(rd,sfa3[i]));
        }
    }

    void get_status_tower_enermy(vector<vector<int>> arr1,vector<vector<int>> arr2){
        status_towers=arr1;
        status_enermy=arr2;
    }


    void check_range(Mix_Chunk *ar,Mix_Chunk *r,Mix_Chunk *fb,bool mode){
        int now=SDL_GetTicks();
        for(int i=0;i<status_towers.size();i++){
            for(int j=0;j<status_enermy.size();j++){
                if (status_towers[i][3]==1&&status_enermy[j][4]>0){
                    int x=abs(status_enermy[j][0]+30-status_towers[i][0]*50-25);
                    int y=abs(status_enermy[j][1]+20-status_towers[i][1]*50-5);
                    if (sqrt(x*x+y*y)<=r_arow+((status_towers[i][4]-1)*50)&&now-status_towers[i][5]>=1200){
                        bullets.push_back({status_towers[i][0]*50+25,status_towers[i][1]*50+5,1,j,status_towers[i][4],0});
                        if(mode) Mix_PlayChannel(-1,ar,0);
                        status_towers[i][5]=now;
                        break;
                    }
                }
                else if (status_towers[i][3]==2&&status_enermy[j][4]>0){
                    int x=abs(status_enermy[j][0]+30-status_towers[i][0]*50-25);
                    int y=abs(status_enermy[j][1]+20-status_towers[i][1]*50-5);
                    if (sqrt(x*x+y*y)<=r_fireball+((status_towers[i][4]-1)*30)&&now-status_towers[i][5]>=900){
                        bullets.push_back({status_towers[i][0]*50+25,status_towers[i][1]*50+5,2,j,status_towers[i][4],0});
                        status_towers[i][5]=now;
                        if(mode) Mix_PlayChannel(-1,fb,0);
                        break;
                    }
                }
                else if (status_towers[i][3]==3&&status_enermy[j][4]>0){
                    int x=abs(status_enermy[j][0]+30-status_towers[i][0]*50-25);
                    int y=abs(status_enermy[j][1]+20-status_towers[i][1]*50-25);
                    if (sqrt(x*x+y*y)<=r_rock+((status_towers[i][4]-1)*30)&&now-status_towers[i][5]>=600){
                        bullets.push_back({status_towers[i][0]*50+25,status_towers[i][1]*50+25,3,j,status_towers[i][4],0});
                        status_towers[i][5]=now;
                        if(mode) Mix_PlayChannel(-1,r,0);
                        break;
                    }
                }
            }
        }
    }


    void find_angle(){
        angle={};
        if(bullets.size()>0){
            for(int i=0;i<bullets.size();i++){
                double arctan= atan2(status_enermy[bullets[i][3]][1]+20-bullets[i][1],status_enermy[bullets[i][3]][0]+30-bullets[i][0]);
                angle.push_back(arctan*180/M_PI);
            }
        }
    }


    void change_status_bul(){
        if(bullets.size()>0){
            for(int i=0;i<bullets.size();i++){
                int dentax=status_enermy[bullets[i][3]][0]+30-bullets[i][0];
                int dentay=status_enermy[bullets[i][3]][1]+20-bullets[i][1];
                int distane=sqrt(dentax*dentax+dentay*dentay);
                if (distane<13){
                    if(bullets[i][2]==1){
                        status_enermy[bullets[i][3]][7]-=(200+100*bullets[i][4]-100);
                        bullets.erase(bullets.begin()+i,bullets.begin()+i+1);
                        i--;
                    }
                    else if(bullets[i][2]==2){
                        status_enermy[bullets[i][3]][7]-=(90+90*bullets[i][4]-90);
                        bullets.erase(bullets.begin()+i,bullets.begin()+i+1);
                        i--;
                    }
                    else if(bullets[i][2]==3){
                        status_enermy[bullets[i][3]][7]-=(25+25*bullets[i][4]-25);
                        bullets.erase(bullets.begin()+i,bullets.begin()+i+1);
                        i--;
                    }
                }
                else if(distane>=13){
                    if(bullets[i][2]==1){
                        int x=dentax*vantoca/distane;
                        int y=dentay*vantoca/distane;
                        bullets[i][0]+=x;
                        bullets[i][1]+=y;
                    }
                    else if(bullets[i][2]==2){
                        int x=dentax*vantocf/distane;
                        int y=dentay*vantocf/distane;
                        bullets[i][0]+=x;
                        bullets[i][1]+=y;
                    }
                    else if(bullets[i][2]==3){
                        int x=dentax*vantocr/distane;
                        int y=dentay*vantocr/distane;
                        bullets[i][0]+=x;
                        bullets[i][1]+=y;
                    }
                }
            }
        }
    }



    void show(SDL_Renderer*rd){
        for(int i=0;i<bullets.size();i++){
            if(bullets[i][2]==1){
                if(bullets[i][4]==1){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,arow1[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=arow1.size())bullets[i][5]=0;
                }
                else if(bullets[i][4]==2){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,arow2[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=arow2.size())bullets[i][5]=0;
                }
                else if(bullets[i][4]==3){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,arow3[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=arow3.size())bullets[i][5]=0;
                }
            }
            else if(bullets[i][2]==2){
                if(bullets[i][4]==1){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,fball1[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=fball1.size())bullets[i][5]=0;
                }
                else if(bullets[i][4]==2){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,fball2[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=fball2.size())bullets[i][5]=0;
                }
                else if(bullets[i][4]==3){
                    SDL_Rect rect={bullets[i][0]-30,bullets[i][1]-30,60,60};
                    SDL_RenderCopyEx(rd,fball3[bullets[i][5]],nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                    bullets[i][5]++;
                    if(bullets[i][5]>=fball3.size())bullets[i][5]=0;
                }
            }
            else if(bullets[i][2]==3){
                if(bullets[i][4]==1){
                    SDL_Rect rect={bullets[i][0]-8,bullets[i][1]-8,16,16};
                    SDL_RenderCopyEx(rd,rok,nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                }
                else if(bullets[i][4]==2){
                    SDL_Rect rect={bullets[i][0]-10,bullets[i][1]-10,20,20};
                    SDL_RenderCopyEx(rd,rok,nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                }
                else if(bullets[i][4]==3){
                    SDL_Rect rect={bullets[i][0]-12,bullets[i][1]-12,24,24};
                    SDL_RenderCopyEx(rd,rok,nullptr,&rect,angle[i],nullptr,SDL_FLIP_NONE);
                }
            }
        }
    }


    vector<vector<int>> return_status_enermy(){
        return status_enermy;
    }

    vector<vector<int>> return_status_towers(){
        return status_towers;
    }

    void clears(){
        bullets.clear();
        angle.clear();
        status_enermy.clear();
        status_towers.clear();
    }

};
