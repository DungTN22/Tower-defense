#include "include file.cpp"


// load ảnh nền
void bg_loading(SDL_Surface *sf,SDL_Renderer *rd){
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={0,0,1400,800};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// hiển thị tên trò chơi
void show_topic_game(SDL_Renderer* rd){
    TTF_Font *font= TTF_OpenFont("font/SuperMario256.ttf",100);
    SDL_Color color0 ={255,165,100,0};
    SDL_Color color1 ={0,0,0,0};
    SDL_Rect size0={235,85,930,280};
    SDL_Rect size1={250,100,900,250};
    SDL_Surface *sf= TTF_RenderText_Blended(font,"TOWER DEFENSE",color0);
    SDL_Surface *sf1= TTF_RenderText_Blended(font,"TOWER DEFENSE",color1);
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
    SDL_RenderCopy(rd,tt,nullptr,&size0);
    tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_RenderCopy(rd,tt,nullptr,&size1);
    SDL_DestroyTexture(tt);
    TTF_CloseFont(font);
}

// hiển thị thanh loading
void loading(SDL_Renderer *rd,SDL_Surface *sf){
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={200,500,1000,80};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// hiển thị thanh vàng của loading
void loading_speed(SDL_Renderer *rd,SDL_Surface *sf,int &length){
    if(length<680){
        length+=10;
    }
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={360,533,length,29};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// hiển thị bảng cảnh cáo 
void show_warning(SDL_Renderer *rd,SDL_Surface *sf ,int &change ,int &index ){
    index+=change;
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_Rect size={300,index,800,600};
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}
