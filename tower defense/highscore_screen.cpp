
// show bảng highscore
void show_highscore_table(SDL_Renderer*rd,SDL_Surface*sf,bool mode,int &index_y){
    if (mode) {if (index_y<100) index_y+=50;}
    else if(mode==false) {if(index_y>-801) index_y-=50;}
    SDL_Rect size={450,index_y,500,600};
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

// show nút ok
void show_ok_in_highscore(SDL_Renderer *rd,SDL_Surface *sf,bool mode,int &index_y){
    if (mode) {if (index_y<625) index_y+=50;}
    else if(mode==false) {if(index_y>-326) index_y-=50;}
    SDL_Rect size={600,index_y,200,80};
    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf);
    SDL_RenderCopy(rd,tt,nullptr,&size);
    SDL_DestroyTexture(tt);
}

void show_three_top_highscore(SDL_Renderer*rd,SDL_Surface *sf1,bool mode ,int &index_y){
    SDL_Color color0 ={255,165,0,0};
    SDL_Color color1 ={255,69,0,0};
    SDL_Color color2 ={139,0,0,0};

    TTF_Font *font=TTF_OpenFont("font/SuperMario256.ttf",20);
    SDL_Surface* ez=TTF_RenderText_Blended(font,"EASY",color0);
    SDL_Surface* med=TTF_RenderText_Blended(font,"MEDIUM",color1);
    SDL_Surface* har=TTF_RenderText_Blended(font,"HARD",color2);

    if (mode) {if (index_y<275) index_y+=50;}
    else if(mode==false) {if(index_y>-626) index_y-=50;}

    SDL_Rect size1={580,index_y,200,80};
    SDL_Rect size2={580,index_y+130,200,80};
    SDL_Rect size3={580,index_y+260,200,80};
    SDL_Rect ezsize={630,index_y-40,100,40};
    SDL_Rect medsize={610,index_y+90,140,40};
    SDL_Rect harsize={630,index_y+220,100,40};


    SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
    SDL_RenderCopy(rd,tt,nullptr,&size1);
    SDL_RenderCopy(rd,tt,nullptr,&size2);
    SDL_RenderCopy(rd,tt,nullptr,&size3);
    SDL_DestroyTexture(tt);

    tt=SDL_CreateTextureFromSurface(rd,ez);
    SDL_RenderCopy(rd,tt,nullptr,&ezsize);
    SDL_DestroyTexture(tt);

    tt=SDL_CreateTextureFromSurface(rd,med);
    SDL_RenderCopy(rd,tt,nullptr,&medsize);
    SDL_DestroyTexture(tt);

    tt=SDL_CreateTextureFromSurface(rd,har);
    SDL_RenderCopy(rd,tt,nullptr,&harsize);
    SDL_DestroyTexture(tt);

    SDL_FreeSurface(ez);SDL_FreeSurface(med);SDL_FreeSurface(har);
    TTF_CloseFont(font);
}




struct scoreplayer{
    string nameez,namemed,namehard;
    int scoreez,scoremed,scorehard;
    SDL_Color white={255,255,255,0};

    scoreplayer(){
        ifstream doc1("map1hsc.txt");
        ifstream doc2("map2hsc.txt");
        ifstream doc3("map3hsc.txt");
        doc1 >> nameez >> scoreez;
        doc2 >> namemed >> scoremed;
        doc3 >> namehard >> scorehard;
        doc1.close();
        doc2.close();
        doc3.close();
    }

    void check_score(int map,int newchiso,string name){
        if (map==1&&newchiso>scoreez){
            nameez=name;
            scoreez=newchiso;
            ofstream viet("map1hsc.txt");
            viet << name << "\n" <<scoreez;
            viet.close();
        }
        else if (map==2&&newchiso>scoremed){
            namemed=name;
            scoremed=newchiso;
            ofstream viet("map2hsc.txt");
            viet << name << "\n" <<scoremed;
            viet.close();
        }
        else if (map==3&&newchiso>scorehard){
            namehard=name;
            scorehard=newchiso;
            ofstream viet("map3hsc.txt");
            viet <<name << "\n" <<scorehard;
            viet.close();
        }
    }

    void show_name(SDL_Renderer *rd,bool mode,int &y){
        TTF_Font *font =TTF_OpenFont("font/BadComic-Regular.ttf",50);

        string sez=to_string(scoreez),smed=to_string(scoremed),shard=to_string(scorehard);    
        int x1=7*nameez.size(),x2=7*namemed.size(),x3=7*namehard.size(),x4=7*sez.size(),x5=7*smed.size(),x6=7*shard.size();
 
        if(mode){if(y<287) y+=50;}
        else {if(y>-614) y-=50;}

        SDL_Rect rect1={650,y,x1,20};// y  chuẩn là 287
        SDL_Rect rect2={650,y+25,x4,20};
        SDL_Rect rect3={650,y+130,x2,20};
        SDL_Rect rect4={650,y+155,x5,20};
        SDL_Rect rect5={650,y+260,x3,20};
        SDL_Rect rect6={650,y+285,x6,20};

        SDL_Surface *sf1=TTF_RenderText_Blended(font,nameez.c_str(),white);
        SDL_Surface *sf2=TTF_RenderText_Blended(font,namemed.c_str(),white);
        SDL_Surface *sf3=TTF_RenderText_Blended(font,namehard.c_str(),white);
        SDL_Surface *sf4=TTF_RenderText_Blended(font,sez.c_str(),white);
        SDL_Surface *sf5=TTF_RenderText_Blended(font,smed.c_str(),white);
        SDL_Surface *sf6=TTF_RenderText_Blended(font,shard.c_str(),white);

        SDL_Texture *tt=SDL_CreateTextureFromSurface(rd,sf1);
        SDL_RenderCopy(rd,tt,nullptr,&rect1);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf4);
        SDL_RenderCopy(rd,tt,nullptr,&rect2);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf2);
        SDL_RenderCopy(rd,tt,nullptr,&rect3);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf5);
        SDL_RenderCopy(rd,tt,nullptr,&rect4);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf3);
        SDL_RenderCopy(rd,tt,nullptr,&rect5);
        SDL_DestroyTexture(tt);

        tt=SDL_CreateTextureFromSurface(rd,sf6);
        SDL_RenderCopy(rd,tt,nullptr,&rect6);
        SDL_DestroyTexture(tt);

        SDL_FreeSurface(sf1);SDL_FreeSurface(sf2);SDL_FreeSurface(sf3);SDL_FreeSurface(sf4);SDL_FreeSurface(sf5);SDL_FreeSurface(sf6);
        TTF_CloseFont(font);
    }
};