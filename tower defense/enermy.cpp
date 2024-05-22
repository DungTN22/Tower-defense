#include "include file.cpp"

class enermy{
    private:
    int time_change_img,time_add_enm,time_set_again,time_to_run;

    vector<SDL_Texture*> emy1={};
    vector<SDL_Texture*> emy2={};
    vector<SDL_Texture*> emy3={};
    vector<SDL_Texture*> emy1die={};
    vector<SDL_Texture*> emy2die={};
    vector<SDL_Texture*> emy3die={};
    vector<vector<int>> die={}; // index_x,index_y,type,mode img;

    vector<vector<int>> status={};  // index_x,index_y,change_x,change_y,type,mode img,time_to_change_img,hp
    int sizex=60,sizey=40,hp=50;
    double sizehp=50.0;
    int sum=0;

    bool spawm_mode=false;

    public:
    int wave =1;
    
    enermy(SDL_Renderer*rd,vector<SDL_Surface*> e1,vector<SDL_Surface*> e2,vector<SDL_Surface*> e3,vector<SDL_Surface*> die1,vector<SDL_Surface*> die2,vector<SDL_Surface*> die3){
        for(int i=0;i<e1.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,e1[i]);
            emy1.push_back(t);
        }
        for(int i=0;i<e2.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,e2[i]);
            emy2.push_back(t);
        }
        for(int i=0;i<e3.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,e3[i]);
            emy3.push_back(t);
        }
        for(int i=0;i<die1.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,die1[i]);
            emy1die.push_back(t);
        }
        for(int i=0;i<die2.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,die2[i]);
            emy2die.push_back(t);
        }
        for(int i=0;i<die3.size();i++){
            SDL_Texture *t=SDL_CreateTextureFromSurface(rd,die3[i]);
            emy3die.push_back(t);
        }
    }

    void change_status(bool ez,bool med,bool har){
        int current=SDL_GetTicks();
        bool mode=false;
        if(ez){
            for(int i=0;i<status.size();i++){
                if (status[i][0]==145 &&status[i][1]==550) {status[i][2]=1;status[i][3]=0;}
                else if (status[i][0]==1095 &&status[i][1]==550) {status[i][2]=0;status[i][3]=-1;}
                if (current-time_to_run>=30){
                    status[i][0]+=status[i][2];
                    status[i][1]+=status[i][3];
                    mode=true;
                }
            }
        }
        else if(med){
            for(int i=0;i<status.size();i++){
                if (status[i][0]==345 &&status[i][1]==200) {status[i][2]=0;status[i][3]=1;}
                if (status[i][0]==345 &&status[i][1]==550) {status[i][2]=1;status[i][3]=0;}
                if (status[i][0]==1095 &&status[i][1]==550) {status[i][2]=0;status[i][3]=-1;}
                if(current-time_to_run>=20){
                    status[i][0]+=status[i][2];
                    status[i][1]+=status[i][3];
                    mode=true;
                }
            }
        }
        else if(har){
            for(int i=0;i<status.size();i++){
                if (status[i][0]==195 &&status[i][1]==300) {status[i][2]=1;status[i][3]=0;}
                else if (status[i][0]==895 &&status[i][1]==300) {status[i][2]=0;status[i][3]=-1;}
                else if (status[i][0]==895 &&status[i][1]==200) {status[i][2]=1;status[i][3]=0;}
                else if (status[i][0]==495 &&status[i][1]==450) {status[i][2]=0;status[i][3]=1;}
                else if (status[i][0]==495 &&status[i][1]==550) {status[i][2]=1;status[i][3]=0;}
                else if (status[i][0]==1095 &&status[i][1]==550) {status[i][2]=0;status[i][3]=-1;}
                else if (status[i][0]==1095 &&status[i][1]==400) {status[i][2]=1;status[i][3]=0;}
                if (current-time_to_run>=10){
                    status[i][0]+=status[i][2];
                    status[i][1]+=status[i][3];
                    mode=true;
                }
            }
        }
        if (mode) time_to_run=SDL_GetTicks();
    }

    void add_enermy(bool ez,bool med,bool har){
        int k=2;
        if (hp<150) k=2;
        else if (hp>=150 && hp<500) k=1;
        else if (hp>=500) k=3;

        if(ez){
            time_change_img=SDL_GetTicks();
            status.push_back({145,0,0,1,k,0,time_change_img,hp});
        }
        else if(med){
            time_change_img=SDL_GetTicks();
            status.push_back({-5,200,1,0,k,0,time_change_img,hp});
        }
        else if(har){
            time_change_img=SDL_GetTicks();
            status.push_back({195,0,0,1,k,0,time_change_img,hp});
            status.push_back({-5,450,1,0,k,0,time_change_img,hp});
        }

    }

    void delete_enermy(int & money , int& score,int &total,int &wave,Mix_Chunk *diel,Mix_Chunk *walkl,bool mode){
        int k=0;
        if(status.size()>0&&mode) Mix_PlayChannelTimed(-1,walkl,0,1000);
        for(int i=0;i<status.size();i++){
            if((status[i][4]<=0 || status[i][0]>=1395|| status[i][1]<=-50)&&status[i][4]>0){
                if(total>0) total--;
                status[i][4]=0;
            }
            if (status[i][7]<=0&&status[i][4]>0){
                if (status[i][4]==2){
                    if(money<10000)money+=1;
                    if(score<10000)score+=10;
                }
                else if (status[i][4]==1){
                    if(money<10000)money+=3;
                    if(score<10000)score+=20;
                }
                else if (status[i][4]==3){
                    if(money<10000)money+=5;
                    if(score<10000)score+=30;
                }
                if(mode) Mix_PlayChannel(-1,diel,0);
                die.push_back({status[i][0],status[i][1],status[i][4],0});
                status[i][4]=0;
            }
            if(status[i][4]==0) k++;
        }
        if (sum==10&&k==status.size()){
            sum=0;time_set_again=SDL_GetTicks();
            status.clear();
            wave++;
            if (hp<100) hp+=20;
            else if (hp>=100 && hp<600) hp+=50;
            else if (hp>=600) hp+=100;
        }
    }

    void start_to_add(bool ez,bool med,bool har){
        int current=SDL_GetTicks();
        if (sum==0&& current-time_set_again>=10000){
            spawm_mode=true;
        }
        else if(sum>=10) {
            spawm_mode=false;  
        }
        if(spawm_mode){
            if(current-time_add_enm>=1500){
                add_enermy(ez,med,har);
                time_add_enm=current;
                sum++;
            }
        }
    }

    void show_hp(SDL_Renderer *rd,SDL_Surface* sf){
        if(status.size()>0){
            double size=sizehp/hp;
            SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
            for(int i=0;i<status.size();i++){
                if (status[i][7]>0){
                    int hpnow= size*status[i][7];
                    SDL_Rect idx={status[i][0]+5,status[i][1],hpnow,7};
                    SDL_RenderCopy(rd,tt,nullptr,&idx);
                }
            }
            SDL_DestroyTexture(tt);
        }
    }

    void show_emy(SDL_Renderer *rd){
        for(int i=0;i<status.size();i++){
            int current=SDL_GetTicks();
            SDL_Rect rect={status[i][0],status[i][1],sizex,sizey};
            if(status[i][5]>=emy1.size()) status[i][5]=0; 
            if (status[i][4]==1){
                SDL_RenderCopy(rd,emy1[status[i][5]],nullptr,&rect);
                if(current-status[i][6]>=100) {
                    status[i][5]++; 
                    status[i][6]=current;
                }
            }
            else if (status[i][4]==2){
                SDL_RenderCopy(rd,emy2[status[i][5]],nullptr,&rect);
                if(current-status[i][6]>=100) {
                    status[i][5]++; 
                    status[i][6]=current;
                }
            }
            else if (status[i][4]==3){
                SDL_RenderCopy(rd,emy3[status[i][5]],nullptr,&rect);
                if(current-status[i][6]>=100) {
                    status[i][5]++;
                    status[i][6]=current;
                }
            }
        }
    }
    void show_emydie(SDL_Renderer*rd){
        if(die.size()>0){
            for(int i=0;i<die.size();i++){
                if(die[i][2]==1){
                    if(die[i][3]<emy1die.size()){
                        SDL_Rect rect={die[i][0],die[i][1],sizex,sizey};
                        SDL_RenderCopy(rd,emy1die[die[i][3]],nullptr,&rect);
                        die[i][3]++;
                    }
                    else {
                        die.erase(die.begin()+i,die.begin()+i+1);
                    }
                }
                if(die[i][2]==2){
                    if(die[i][3]<emy2die.size()){
                        SDL_Rect rect={die[i][0],die[i][1],sizex,sizey};
                        SDL_RenderCopy(rd,emy2die[die[i][3]],nullptr,&rect);
                        die[i][3]++;
                    }
                    else {
                        die.erase(die.begin()+i,die.begin()+i+1);
                    }
                }
                if(die[i][2]==3){
                    if(die[i][3]<emy3die.size()){
                        SDL_Rect rect={die[i][0],die[i][1],sizex,sizey};
                        SDL_RenderCopy(rd,emy3die[die[i][3]],nullptr,&rect);
                        die[i][3]++;
                    }
                    else {
                        die.erase(die.begin()+i,die.begin()+i+1);
                    }
                }
            }
        }
    }

    void run(SDL_Renderer*rd,bool ez,bool med,bool hard,SDL_Surface *Sf){
        start_to_add(ez,med,hard);
        show_emy(rd);
        show_hp(rd,Sf);
        change_status(ez,med,hard);
    }

    void clear(){
        status.clear();
        hp=50;
    }
    void start_game(bool ez,bool med,bool hard){
        time_change_img=SDL_GetTicks();
        time_add_enm=SDL_GetTicks();
        time_set_again=SDL_GetTicks();
        time_to_run=SDL_GetTicks();
        spawm_mode=false;
        wave=1;sum=0;
    }

    vector<vector<int>> get_enermy(){
        return status;
    }
    void tra_ham(vector<vector<int>> arr){
        status=arr;
    }
};