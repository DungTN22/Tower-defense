
// show nền 
void show_bg_enter(SDL_Renderer*rd,SDL_Surface *sf){
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={0,0,1400,800};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// show bảng điền thông tin
void show_table_enter(SDL_Renderer *rd,SDL_Surface *sf ){
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={300,100,800,600};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

//show thanh trắng điền tên
void show_enter_tool(SDL_Renderer *rd){
    SDL_SetRenderDrawColor(rd,255,255,255,0);
    SDL_Rect idx={550,465,300,60};
    SDL_RenderFillRect(rd,&idx);
    SDL_SetRenderDrawColor(rd,0,0,0,0);
}

//show chữ welcome
void show_welcome(SDL_Renderer *rd){
    TTF_Font *font= TTF_OpenFont("font/SuperMario256.ttf",100);
    SDL_Rect idx={570,130,250,70};
    SDL_Color color={255,165,0,0};
    SDL_Surface *sf = TTF_RenderText_Blended(font,"WELCOME",color);
    SDL_Texture *tt= SDL_CreateTextureFromSurface(rd,sf);
    SDL_RenderCopy(rd,tt,nullptr,&idx);
    SDL_DestroyTexture(tt);
    SDL_FreeSurface(sf);
    TTF_CloseFont(font);
}

// show gợi í chỗ điền
void show_instruct_enter(SDL_Renderer *rd){
    TTF_Font *font =TTF_OpenFont("font/FiraMono-Regular.ttf",100);
    SDL_Rect idx={470,300,450,100};
    SDL_Color color={255,255,255,0};
    SDL_Surface *sf = TTF_RenderText_Blended(font,"Please enter Your Name!",color);
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_RenderCopy(rd,tt,nullptr,&idx);
    SDL_DestroyTexture(tt);
    SDL_FreeSurface(sf);
    TTF_CloseFont(font);
}

// hiển thị tên
void enter_name(SDL_Renderer *rd, string name){
    TTF_Font *font =TTF_OpenFont("font/FiraMono-Regular.ttf",100);
    SDL_Texture *tt;
    if (name.size()==0){
        SDL_Rect idx={560,475,280,40};
        SDL_Color color = {165,165,165,0};
        SDL_Surface *sf = TTF_RenderText_Blended(font,"enter name here",color);
        tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&idx);
        SDL_FreeSurface(sf);
    }
    else {
        int size=name.size();
        SDL_Rect idx={560,475,18*size,40};
        SDL_Color color = {0,0,0,0};
        SDL_Surface *sf = TTF_RenderText_Blended(font,name.c_str(),color);
        tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&idx);
        SDL_FreeSurface(sf);
    }
    SDL_DestroyTexture(tt);
    TTF_CloseFont(font);
}