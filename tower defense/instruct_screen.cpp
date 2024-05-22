
// show cửa sổ i
void show_instruct_table(SDL_Renderer*rd ,SDL_Surface *sf,bool mode){
    if(mode){
        SDL_Rect size={450,150,500,550};
        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&size);
        SDL_DestroyTexture(tt);
    }
}

// show nút ok
void show_ok_in_instruct(SDL_Renderer *rd,SDL_Surface *sf,bool mode){
    if(mode){
        SDL_Rect size={600,625,200,80};
        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_RenderCopy(rd,tt,nullptr,&size);
        SDL_DestroyTexture(tt);
    }
}

void show_text_instruct(SDL_Renderer *rd ,bool mode,SDL_Surface *sf){
    if(mode){
        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
        SDL_Rect rect={500,175,400,480};
        SDL_RenderCopy(rd,tt,nullptr,&rect);
        SDL_DestroyTexture(tt);
    }   
}