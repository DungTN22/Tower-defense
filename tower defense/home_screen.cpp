const int WIDTH=1400;
const int HEIGHT=800;
// tạo hiệu ứng màn hình đen chạy qua
void clear_for_home(SDL_Renderer* rd,int &x){
    SDL_SetRenderDrawColor(rd,0,0,0,0);
    SDL_Rect rect={x,0,1400,800};
    SDL_RenderFillRect(rd,&rect);
    x-=14;
}

// hiển thị background home
void show_bg_home(SDL_Renderer*rd,SDL_Surface* sf){
    SDL_Rect rect={0,0,WIDTH,HEIGHT};
    SDL_RenderFillRect(rd,&rect);
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={0,0,WIDTH,HEIGHT};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// hiển thị bảng level ở home
void show_table_level(SDL_Renderer*rd,SDL_Surface* sf){
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={200,100,1000,600};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// hiện thị các cánh cửa của các màn chơi
void show_gate_mode(SDL_Renderer *rd,vector<SDL_Surface*> sf,int mode,int index_x){
    SDL_Texture *tt;
    SDL_Rect rect={index_x,350,150,200};
    if(mode==1){
        tt=SDL_CreateTextureFromSurface(rd,sf[0]);
        SDL_RenderCopy(rd,tt,nullptr,&rect);
    }
    else if(mode==0){
        tt=SDL_CreateTextureFromSurface(rd,sf[1]);
        SDL_RenderCopy(rd,tt,nullptr,&rect);
    }
    SDL_DestroyTexture(tt);
}

// hiển thị tên mức độ màn chơi
void render_text_level(SDL_Renderer*rd){
    TTF_Font*font= TTF_OpenFont("font/SuperMario256.ttf",100);

    SDL_Color color0 ={255,165,0,0};
    SDL_Color color1 ={255,69,0,0};
    SDL_Color color2 ={139,0,0,0};

    SDL_Rect idx1={405,270,100,50};
    SDL_Rect idx2={640,270,140,50};
    SDL_Rect idx3={905,270,100,50};

    SDL_Surface *sf0 = TTF_RenderText_Blended(font,"EASY",color0);
    SDL_Surface *sf1 = TTF_RenderText_Blended(font,"MEDIUM",color1);
    SDL_Surface *sf2 = TTF_RenderText_Blended(font,"HARD",color2);

    SDL_Texture*tt=SDL_CreateTextureFromSurface(rd,sf0);
    SDL_RenderCopy(rd,tt,nullptr,&idx1);
    SDL_DestroyTexture(tt);

    tt=SDL_CreateTextureFromSurface(rd,sf1);
    SDL_RenderCopy(rd,tt,nullptr,&idx2);
    SDL_DestroyTexture(tt);
    
    tt=SDL_CreateTextureFromSurface(rd,sf2);
    SDL_RenderCopy(rd,tt,nullptr,&idx3);
    SDL_DestroyTexture(tt);

    SDL_FreeSurface(sf0);SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);
    TTF_CloseFont(font);
}

// hiển thị các icon
void show_icon(SDL_Renderer*rd,vector<SDL_Surface*> sf,int mode,int index_x){
    SDL_Texture *tt;
    SDL_Rect rect={index_x,20,80,80};
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

//hiển thị xóa phông trước khi vào game
void show_blackcirle(SDL_Renderer*rd,SDL_Surface*sf,int mode,int&x,int&y,int&l,int&s){
    if(mode<2){
        if(mode==0) {
            if(x>-300) {
                x-=20;y-=20;l+=40;s+=40;
            }
        }
        else if(mode==1) {
            if(x<700) {
                x+=20;y+=20;l-=40;s-=40;
            }
        }
        SDL_Rect rect={x,y,l,s};
        SDL_Texture*tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&rect);
        SDL_DestroyTexture(tt);
    }
}