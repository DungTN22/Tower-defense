#include "start_screen.cpp"
#include "enter_name_screen.cpp"
#include "home_screen.cpp"
#include "highscore_screen.cpp"
#include "instruct_screen.cpp"
#include "enermy.cpp"
#include "loading_map.cpp"
#include "tower.cpp"
#include "projectiles.cpp"
#include "value.cpp"
#include "end.cpp"
#include "sound.cpp"
#include "object.cpp"



int main(int arcv,char*argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    
    // music
    Mix_Music *sound_bg=Mix_LoadMUS("sound/level.mp3");
    Mix_Chunk *sound_over=Mix_LoadWAV("sound/gameover.wav");
    Mix_Chunk *sound_newgame=Mix_LoadWAV("sound/newgame.wav");
    Mix_Chunk *sound_built=Mix_LoadWAV("sound/hit.wav");
    Mix_Chunk *sound_fb=Mix_LoadWAV("sound/towerBuilt.wav");
    Mix_Chunk *sound_ar=Mix_LoadWAV("sound/arrow.wav");
    Mix_Chunk *sound_r=Mix_LoadWAV("sound/rock.wav");
    Mix_Chunk *sound_die=Mix_LoadWAV("sound/death.wav");
    Mix_Chunk *sound_walk=Mix_LoadWAV("sound/bone-crack-121580.mp3");
    SDL_SetRenderDrawColor(render,0,0,0,0);
    int time=SDL_GetTicks();

    //STRUCT AND CLASS
    
    tilemap map1;
    tilemap map2;
    tilemap map3;
    map1.import_map("map1.txt",ground,render);
    map2.import_map("map2.txt",ground,render);
    map3.import_map("map3.txt",ground,render);

    enermy spawmenermy{render,enermy1_walk,enermy2_walk,enermy3_walk,enermy1_die,enermy2_die,enermy3_die};
    vector<vector<int>> todoa_enermy;

    extra_gui newextra(render,extra_item);

    tower supertower(render,archer,castle_t,knight,empty_bt);
    supertower.get_index("map1.txt","map2.txt","map3.txt");


    vector<vector<int>> toado_tower;
    vector<vector<int>> indexs_have_tower;
    vector<int> get;


    bullet rocket(render,rock,fireballed1,fireballed2,fireballed3,arrowred1,arrowred2,arrowred3);
    vector<vector<int>> status_enermy_afterchange;
    vector<vector<int>> status_towers_afterchange;

    chi_so chiso(render,congcu);

    endgame thua(render,over);

    arua vibe(render,yellow_arua,blue_arua);

    scoreplayer diemcao;


    while(true){
        if(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                break;
            }
            if(start_window){
                if(index_x_warning==100)
                    if (event.type==SDL_MOUSEBUTTONDOWN){
                        int mouseX=event.motion.x;
                        int mouseY=event.motion.y;
                        if(mouseX>=568 &&mouseX <=828 && mouseY >=577 && mouseY <=697){ // tọa độ của chuột thỏa mãn nằm trong nút ok
                            change_x_warning=-30;
                        }
                    }
            }
            if(enter_name_window){
                if (event.type==SDL_KEYDOWN){
                    if(your_name.size()<15&&your_name.size()>=0){
                        switch (event.key.keysym.sym){
                            case SDLK_a: your_name+='a'; break;
                            case SDLK_b: your_name+='b'; break;
                            case SDLK_c: your_name+='c'; break;
                            case SDLK_d: your_name+='d'; break;
                            case SDLK_e: your_name+='e'; break;
                            case SDLK_f: your_name+='f'; break;
                            case SDLK_g: your_name+='g'; break;
                            case SDLK_h: your_name+='h'; break;
                            case SDLK_i: your_name+='i'; break;
                            case SDLK_k: your_name+='k'; break;
                            case SDLK_l: your_name+='l'; break;
                            case SDLK_m: your_name+='m'; break;
                            case SDLK_n: your_name+='n'; break;
                            case SDLK_o: your_name+='o'; break;
                            case SDLK_p: your_name+='p'; break;
                            case SDLK_q: your_name+='q'; break;
                            case SDLK_r: your_name+='r'; break;
                            case SDLK_s: your_name+='s'; break;
                            case SDLK_t: your_name+='t'; break;
                            case SDLK_u: your_name+='u'; break;
                            case SDLK_v: your_name+='v'; break;
                            case SDLK_x: your_name+='x'; break;
                            case SDLK_y: your_name+='y'; break;
                            case SDLK_z: your_name+='z'; break;
                            case SDLK_w: your_name+='w'; break;
                            case SDLK_SPACE : your_name+=' ';break;
                            case SDLK_BACKSPACE:
                            if(your_name.size()>=1) your_name.erase(your_name.end()-1,your_name.end());break;
                        }
                    }
                    // phím enter
                    if (your_name.size()>0 && event.key.keysym.scancode==SDL_SCANCODE_RETURN){
                        enter_name_window=false;
                        home_window=true;
                        load_home=WIDTH;
                        Mix_PlayMusic(sound_bg, -1);
                    }
                }
            }
            if(show_score){
                int x=event.motion.x;
                int y=event.motion.y;
                if (event.type==SDL_MOUSEBUTTONDOWN){
                    if(x>=575&&x<=825&&y>=560&&y<=660){
                        home_window=true;easy_window=false;medium_window=false;hard_window=false;
                        thua.clear_all();
                        show_score=false;
                        gameover=false;
                        chiso.tottal=1;
                    }
                }
            }
            if (easy_window||medium_window||hard_window){
                int mouse_x=event.motion.x;
                int mouse_y=event.motion.y;
                if (mouse_x>=10&& mouse_x<=50 && mouse_y>=10 &&mouse_y<=50) home_icon_mode=1; 
                else home_icon_mode=0;
                if (mouse_x>=60&& mouse_x<=100 && mouse_y>=10 &&mouse_y<=50) sound_icon_mode=1; 
                else sound_icon_mode=0;
                for(int i=0;i<toado_tower.size();i++){
                    if (mouse_x>=toado_tower[i][0]*50 && mouse_x<=toado_tower[i][0]*50+50&&mouse_y>=toado_tower[i][1]*50&&mouse_y<=toado_tower[i][1]*50+50){
                        if (toado_tower[i][3]==0){
                            trangthai_tower=true;
                            get={toado_tower[i][0],toado_tower[i][1],toado_tower[i][2],i,toado_tower[i][4]};// i vectorcon thỏa mãn dk dùng check trạng thái xem hiển thị mua hay upgrade
                            break;
                        }
                        else if (toado_tower[i][3]==1){
                            show_craft=true;
                            get={toado_tower[i][0],toado_tower[i][1],toado_tower[i][2],i,toado_tower[i][4]};
                            break;
                        }
                    }
                    else {
                        trangthai_tower=false;
                        show_craft=false;
                    }
                }
            }
            if(trangthai_tower){
                if(event.type==SDL_MOUSEBUTTONDOWN){
                    show_trangthai=true;
                }
            }
            if(show_trangthai){
                int mouse_x=event.motion.x;
                int mouse_y=event.motion.y;
                if (mouse_x<get[0]*50-120|| mouse_x>get[0]*50+150 || mouse_y<get[1]*50-100||mouse_y>get[1]*50+100) show_trangthai=false;
                if (mouse_x>=get[0]*50-75&& mouse_x<=get[0]*50-15 && mouse_y>=get[1]*50-70&&mouse_y<=get[1]*50-10) {
                    arch_mode=true;
                }
                else arch_mode=false;
                if (mouse_x>=get[0]*50-5&& mouse_x<=get[0]*50+55 && mouse_y>=get[1]*50-70&&mouse_y<=get[1]*50-10) {
                    cast_mode=true;
                }
                else cast_mode=false;
                if (mouse_x>=get[0]*50+65&& mouse_x<=get[0]*50+125 && mouse_y>=get[1]*50-70&&mouse_y<=get[1]*50-10) {
                    knt_mode=true;
                }
                else knt_mode=false;
            }
            if (arch_mode){
                kieu_tower="arrow";
                if(event.type==SDL_MOUSEBUTTONDOWN){
                    if(chiso.gold>=100){
                        chiso.gold-=100;
                        supertower.add_tower(get[0],get[1],get[2],1,get[4]);
                        toado_tower[get[3]][3]=1;toado_tower[get[3]][5]=1;
                        show_trangthai=false;
                        arch_mode=false;
                        kieu_tower="";
                        if(sound_window) Mix_PlayChannel(-1,sound_built,0);
                    }
                }
            }
            else if(cast_mode){
                kieu_tower="fireball";
                if(event.type==SDL_MOUSEBUTTONDOWN){
                    if(chiso.gold>=50){
                        chiso.gold-=50;
                        supertower.add_tower(get[0],get[1],get[2],2,get[4]);
                        toado_tower[get[3]][3]=1;toado_tower[get[3]][5]=2;
                        show_trangthai=false;
                        cast_mode=false;
                        kieu_tower="";
                        if(sound_window) Mix_PlayChannel(-1,sound_built,0);
                    }
                }
            }
            else if(knt_mode){
                kieu_tower="knight";
                if(event.type==SDL_MOUSEBUTTONDOWN){
                    if(chiso.gold>=10){
                        chiso.gold-=10;
                        supertower.add_tower(get[0],get[1],get[2],3,get[4]);
                        toado_tower[get[3]][3]=1;toado_tower[get[3]][5]=3;
                        show_trangthai=false;
                        knt_mode=false;
                        kieu_tower="";
                        if(sound_window) Mix_PlayChannel(-1,sound_built,0);
                    }
                }
            }
            if(show_craft){
                if (event.type==SDL_MOUSEBUTTONDOWN){
                    crafting=true;
                }
            }
            if (crafting){
                int mouse_x= event.motion.x;
                int mouse_y= event.motion.y;
                if (mouse_x>=get[0]*50-75&&mouse_x<=get[0]*50+20&&mouse_y>=get[1]*50-60&&mouse_y<=get[1]*50-30){
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        supertower.delete_tower(get[0],get[1],chiso.gold);
                        toado_tower[get[3]][4]=1;
                        toado_tower[get[3]][3]=0;
                        toado_tower[get[3]][5]=0;
                        show_craft=false;
                        crafting=false;
                    }
                }
                else if (mouse_x>=get[0]*50+30&&mouse_x<=get[0]*50+125&&mouse_y>=get[1]*50-60&&mouse_y<=get[1]*50-30){
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        int k=chiso.gold;
                        if(toado_tower[get[3]][4]<3) {
                            toado_tower[get[3]][4]++;
                            supertower.upgrade(get[0],get[1],chiso.gold);
                            if(k==chiso.gold) toado_tower[get[3]][4]--;
                            else if(k!=chiso.gold) {
                                vibe_mode=true;
                                time=SDL_GetTicks();
                            }
                        }
                        show_craft=false;
                        crafting=false;
                    }
                }
                else if (mouse_x<get[0]*50-90||mouse_x>get[0]*50+140||mouse_y<get[1]*50-140||mouse_y>get[1]*50+70){
                    show_craft=false;
                    crafting=false;
                }
            }
            if (home_window){
                int mouse_x=event.motion.x;
                int mouse_y=event.motion.y;
                if (mouse_x>=380&& mouse_x<=380+150 && mouse_y>=350 &&mouse_y<=550) gate_mode0=1; 
                else gate_mode0=0;
                if (mouse_x>=630&& mouse_x<=630+150 && mouse_y>=350 &&mouse_y<=550) gate_mode1=1; 
                else gate_mode1=0;
                if (mouse_x>=880&& mouse_x<=880+150 && mouse_y>=350 &&mouse_y<=550) gate_mode2=1; 
                else gate_mode2=0;
                if (mouse_x>=20&& mouse_x<=100 && mouse_y>=20 &&mouse_y<=100) return_icon_mode=1; 
                else return_icon_mode=0;
                if (mouse_x>=120&& mouse_x<=200 && mouse_y>=20 &&mouse_y<=100) i_icon_mode=1; 
                else i_icon_mode=0;
                if (mouse_x>=1200&& mouse_x<=1280 && mouse_y>=20 &&mouse_y<=100) highscore_icon_mode=1; 
                else highscore_icon_mode=0;
                if (mouse_x>=1300&& mouse_x<=1380 && mouse_y>=20 &&mouse_y<=100) sound_icon_mode=1; 
                else sound_icon_mode=0;

            }

            // in home screen
            if (return_icon_mode==1){
                if (event.type==SDL_MOUSEBUTTONDOWN) break;
            }
            else if (highscore_icon_mode==1){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    highscore_window=true;instruct_window=false;
                    highscore_icon_mode=0;
                }
            }
            else if (i_icon_mode==1){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    instruct_window=true;highscore_window=false;
                    i_icon_mode=0;
                }
            }
            else if (home_icon_mode==1){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    home_window=true;easy_window=false;medium_window=false;hard_window=false;
                    home_icon_mode=0;
                }
            }
            else if(sound_icon_mode==1){
                if(event.type==SDL_MOUSEBUTTONDOWN) {
                    if (sound_window) {
                        sound_window=false;
                    }
                    else if(sound_window==false) {
                        sound_window=true;
                    }
                }
            }

            // gate
            if (gate_mode0==1&&highscore_window==false&&instruct_window==false){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    instruct_window=false;highscore_window=false;
                    home_window=false,easy_window=true,gate_mode0=0,load_home=WIDTH;
                    spawmenermy.clear(),spawmenermy.start_game(easy_window,medium_window,hard_window),clear=0;
                    supertower.clear_tower();rocket.clears();
                    toado_tower=supertower.return_index(1);
                    trangthai_tower=false;show_trangthai=false;
                    chiso.update_total_gold(gold_ez,total_ez);
                    Mix_HaltMusic();
                }
            }
            if (gate_mode1==1&&highscore_window==false&&instruct_window==false){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    instruct_window=false;highscore_window=false;
                    home_window=false,medium_window=true,gate_mode1=0,load_home=WIDTH;
                    spawmenermy.clear(),spawmenermy.start_game(easy_window,medium_window,hard_window),clear=0;
                    supertower.clear_tower();rocket.clears();
                    toado_tower=supertower.return_index(2);
                    trangthai_tower=false;show_trangthai=false;
                    chiso.update_total_gold(gold_medium,total_med);
                    Mix_HaltMusic();
                }
            }
            if (gate_mode2==1&&highscore_window==false&&instruct_window==false){
                if (event.type==SDL_MOUSEBUTTONDOWN) {
                    instruct_window=false;highscore_window=false;
                    home_window=false,hard_window=true,gate_mode2=0,load_home=WIDTH;
                    spawmenermy.clear(),spawmenermy.start_game(easy_window,medium_window,hard_window),clear=0;
                    supertower.clear_tower();rocket.clears();
                    toado_tower=supertower.return_index(3);
                    trangthai_tower=false;show_trangthai=false;
                    chiso.update_total_gold(gold_hard,total_hard);
                    Mix_HaltMusic();
                }
            }

            //  istruct and highscore
            if (table_highscore_y==100){
                int mouse_x=event.motion.x;
                int mouse_y=event.motion.y;
                if(mouse_x>=600 && mouse_x<=800 && mouse_y>=625&&mouse_y<=705){
                    if(event.type==SDL_MOUSEBUTTONDOWN) highscore_window=false;
                }
            }
            if (instruct_window){
                int mouse_x=event.motion.x;
                int mouse_y=event.motion.y;
                if(mouse_x>=600 && mouse_x<=800 && mouse_y>=625&&mouse_y<=705){
                    if(event.type==SDL_MOUSEBUTTONDOWN) instruct_window=false;
                }
            }
            
        }
        if(start_window){
            SDL_RenderClear(render);
            bg_loading(background_loading,render);
            if(length_loading<680){
                show_topic_game(render);
                loading(render,loading_size);
                loading_speed(render,loading_size_speed,length_loading);
            }
            else if(length_loading>=680){
                show_warning(render,warning_load,change_x_warning,index_x_warning);
                if(index_x_warning==100) change_x_warning=0;
                if (index_x_warning<-800){
                    start_window=false;
                    enter_name_window=true;
                }
            }
        }
        if(enter_name_window){
            SDL_RenderClear(render);
            show_bg_enter(render,background_entering);
            show_table_enter(render,enter_table);
            show_enter_tool(render);
            show_welcome(render);
            show_instruct_enter(render);
            enter_name(render,your_name);
        }
        if(home_window){
            if (sound_window && !Mix_PlayingMusic()) Mix_PlayMusic(sound_bg, -1);
            else if (sound_window==false) Mix_HaltMusic(); 
            if(load_home>=-WIDTH){
                if(load_home<0) show_bg_home(render,background_home);
                clear_for_home(render,load_home);
            }
            else{
                show_bg_home(render,background_home);
                show_table_level(render,table_level);
                show_gate_mode(render,gate,gate_mode0,380);
                show_gate_mode(render,gate,gate_mode1,630);
                show_gate_mode(render,gate,gate_mode2,880);
                show_icon(render,return_icon,return_icon_mode,20);
                show_icon(render,i_icon,i_icon_mode,120);
                show_icon(render,highscore_icon,highscore_icon_mode,1200);
                show_icon(render,sound_icon,sound_icon_mode,1300);
                render_text_level(render);
                show_highscore_table(render,highscore_table,highscore_window,table_highscore_y);
                show_ok_in_highscore(render,ok_button0,highscore_window,back_y_in_high_score);
                show_three_top_highscore(render,thanh_highscore,highscore_window,top1_y);
                diemcao.show_name(render,highscore_window,topy);
                show_instruct_table(render,instruct_table,instruct_window);
                show_text_instruct(render,instruct_window,title);
                show_ok_in_instruct(render,ok_button0,instruct_window);
            }
        }
        if (gameover==false&& show_score==false){
            if (easy_window){
                if(clear>=1){
                    if (chiso.tottal<=0){
                        gameover=true;thua.last=SDL_GetTicks();
                        diemcao.check_score(1,chiso.score,your_name);
                        if(sound_window) Mix_PlayChannel(-1, sound_over, 0);
                    }
                    SDL_RenderClear(render);
                    map1.export_map(render);
                    newextra.draw_extra_map1(render,extra1);
                    spawmenermy.run(render,easy_window,medium_window,hard_window,hp_thanh);
                    spawmenermy.show_emydie(render);
                    if(show_trangthai) supertower.show_menu_select_tower(render,get[0],get[1]);
                    supertower.show_tower(render);
                    if (cast_mode||knt_mode||arch_mode) {
                        supertower.show_status_tower(render,get[0],get[1]);
                        chiso.show_cost_and_value(render,get[0],get[1],kieu_tower);
                    }
                    if (crafting) {
                        supertower.show_sell_or_ugr(render,get[0],get[1],get[4]);
                        chiso.show_thongso_sell_upgrade(render,get[0],get[1],toado_tower[get[3]][5],toado_tower[get[3]][4]);
                    }
                    chiso.show_thanhcongcu(render);chiso.show_value(render);
                    todoa_enermy=spawmenermy.get_enermy();
                    indexs_have_tower=supertower.index_spawmtower();
                    rocket.get_status_tower_enermy(indexs_have_tower,todoa_enermy);
                    rocket.check_range(sound_ar,sound_r,sound_fb,sound_window);
                    rocket.find_angle();rocket.show(render);rocket.change_status_bul();
                    status_enermy_afterchange=rocket.return_status_enermy();
                    status_towers_afterchange=rocket.return_status_towers();
                    supertower.get_spawmtower(status_towers_afterchange);
                    spawmenermy.tra_ham(status_enermy_afterchange);
                    spawmenermy.delete_enermy(chiso.gold,chiso.score,chiso.tottal,chiso.wave,sound_die,sound_walk,sound_window);
                    show_icon_in_game(render,home_button,home_icon_mode,10);
                    show_icon_in_game(render,sound_icon,sound_icon_mode,60);
                }
                if(clear<2){
                    if(clear==0 && clear_x==-300) clear++;
                    else if (clear==1&& clear_x==700) clear++;
                    show_blackcirle(render,backcircle,clear,clear_x,clear_y,clear_l,clear_s);
                    if (clear==1&& sound_window&&clear_x==700) Mix_PlayChannel(-1, sound_newgame, 0);
                }
            }
            if(medium_window){
                if(clear>=1){
                    if (chiso.tottal<=0){
                        gameover=true;thua.last=SDL_GetTicks();
                        diemcao.check_score(2,chiso.score,your_name);
                        if(sound_window) Mix_PlayChannel(-1, sound_over, 0);
                    }
                    SDL_RenderClear(render);
                    map2.export_map(render);
                    newextra.draw_extra_map2(render,extra2);
                    spawmenermy.run(render,easy_window,medium_window,hard_window,hp_thanh);
                    spawmenermy.show_emydie(render);
                    if(show_trangthai) supertower.show_menu_select_tower(render,get[0],get[1]);
                    supertower.show_tower(render);
                    if (cast_mode||knt_mode||arch_mode) {
                        supertower.show_status_tower(render,get[0],get[1]);
                        chiso.show_cost_and_value(render,get[0],get[1],kieu_tower);
                    }
                    if (crafting) {
                        supertower.show_sell_or_ugr(render,get[0],get[1],get[4]);
                        chiso.show_thongso_sell_upgrade(render,get[0],get[1],toado_tower[get[3]][5],toado_tower[get[3]][4]);
                    }
                    chiso.show_thanhcongcu(render);chiso.show_value(render);
                    todoa_enermy=spawmenermy.get_enermy();
                    indexs_have_tower=supertower.index_spawmtower();
                    rocket.get_status_tower_enermy(indexs_have_tower,todoa_enermy);
                    rocket.check_range(sound_ar,sound_r,sound_fb,sound_window);
                    rocket.find_angle();rocket.show(render);rocket.change_status_bul();
                    status_enermy_afterchange=rocket.return_status_enermy();
                    status_towers_afterchange=rocket.return_status_towers();
                    supertower.get_spawmtower(status_towers_afterchange);
                    spawmenermy.tra_ham(status_enermy_afterchange);
                    spawmenermy.delete_enermy(chiso.gold,chiso.score,chiso.tottal,chiso.wave,sound_die,sound_walk,sound_window);
                    show_icon_in_game(render,home_button,home_icon_mode,10);
                    show_icon_in_game(render,sound_icon,sound_icon_mode,60);
                }
                if(clear<2){
                    if(clear==0 && clear_x==-300) clear++;
                    else if (clear==1&& clear_x==700) clear++;
                    show_blackcirle(render,backcircle,clear,clear_x,clear_y,clear_l,clear_s);
                    if (clear==1&& sound_window&&clear_x==700) Mix_PlayChannel(-1, sound_newgame, 0);
                }
            }
            if(hard_window){
                if(clear>=1){
                    if (chiso.tottal<=0){
                        gameover=true;thua.last=SDL_GetTicks();
                        diemcao.check_score(3,chiso.score,your_name);
                        if(sound_window) Mix_PlayChannel(-1, sound_over, 0);
                    }
                    SDL_RenderClear(render);
                    map3.export_map(render);
                    newextra.draw_extra_map3(render,extra3);
                    spawmenermy.run(render,easy_window,medium_window,hard_window,hp_thanh);
                    spawmenermy.show_emydie(render);
                    if(show_trangthai) supertower.show_menu_select_tower(render,get[0],get[1]);
                    supertower.show_tower(render);
                    if (cast_mode||knt_mode||arch_mode) {
                        supertower.show_status_tower(render,get[0],get[1]);
                        chiso.show_cost_and_value(render,get[0],get[1],kieu_tower);
                    }
                    if (crafting) {
                        supertower.show_sell_or_ugr(render,get[0],get[1],get[4]);
                        chiso.show_thongso_sell_upgrade(render,get[0],get[1],toado_tower[get[3]][5],toado_tower[get[3]][4]);
                    }
                    chiso.show_thanhcongcu(render);chiso.show_value(render);
                    todoa_enermy=spawmenermy.get_enermy();
                    indexs_have_tower=supertower.index_spawmtower();
                    rocket.get_status_tower_enermy(indexs_have_tower,todoa_enermy);
                    rocket.check_range(sound_ar,sound_r,sound_fb,sound_window);
                    rocket.find_angle();rocket.show(render);rocket.change_status_bul();
                    status_enermy_afterchange=rocket.return_status_enermy();
                    status_towers_afterchange=rocket.return_status_towers();
                    supertower.get_spawmtower(status_towers_afterchange);
                    spawmenermy.tra_ham(status_enermy_afterchange);
                    spawmenermy.delete_enermy(chiso.gold,chiso.score,chiso.tottal,chiso.wave,sound_die,sound_walk,sound_window);
                    show_icon_in_game(render,home_button,home_icon_mode,10);
                    show_icon_in_game(render,sound_icon,sound_icon_mode,60);
                }
                if(clear<2){
                    if(clear==0 && clear_x==-300) clear++;
                    else if (clear==1&& clear_x==700) clear++;
                    show_blackcirle(render,backcircle,clear,clear_x,clear_y,clear_l,clear_s);
                    if (clear==1&& sound_window&&clear_x==700) Mix_PlayChannel(-1, sound_newgame, 0);
                }
            }
            if (vibe_mode){
                int now=SDL_GetTicks();
                if(cut_vibey<3) {
                    vibe.show_arua(render,get[0],get[1],cut_vibex,cut_vibey,toado_tower[get[3]][4]);
                    if(now-time>=100){
                        cut_vibex++;time=now;
                    }
                    if(cut_vibex>=6){
                        cut_vibex=1;cut_vibey++;
                    }
                }
                else if(cut_vibey>=3) {
                    vibe_mode=false;cut_vibex=1;cut_vibey=1;
                }
            }
        }

        else if(gameover){
            thua.show_text_gameover(render,show_score,gameover);
        }

        if (show_score){
            SDL_RenderClear(render);
            thua.show_table_score(render);
            thua.show_score_gold_name(render,chiso.score,chiso.gold,your_name);
        }

        SDL_RenderPresent(render);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
    return EXIT_SUCCESS;
}