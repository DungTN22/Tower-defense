# Tác giả 
Nguyễn Tiến Dũng
-23020592

# Mô tả
-Tower Defense là trò chơi mang tính chiến lược , trong trò chơi sẽ có lần lượt những đợt sóng(zombie) tiến đến nhằm phá hủy thành của ta 
và zombie sẽ trâu hơn sau mỗi đợt sóng khiến ta vô cùng khó khăn trong việc chống lại chúng ,chính vì vậy ta cần phải có chiến lược khôn
khéo trong việc xây dựng cũng như nâng cấp thành để vượt qua nhiều đợt sóng nhất có thể

![Screenshot 2024-05-22 225953](https://github.com/DungTN22/Tower-defense/assets/161128678/43be197e-dbc5-43bb-93e1-677043ae0e17)

- Người chơi có điểm cao nhất sẽ được lưu danh vào sử sách của game

![Screenshot 2024-05-22 224831](https://github.com/DungTN22/Tower-defense/assets/161128678/c0328481-a23a-4058-a3db-13fc8c888507)


# Cách chơi
-Bấm vào nhưng ô đất trống mua những tòa thành để tiêu diệt thây ma đang cố gắng tiến về đích (phải đủ tiền nhé). 

-Hãy khôn ngoan trong việc nâng cấp và mua thành mới để có thể vượt qua nhiều đợt sóng nhất.


![Screenshot 2024-05-22 224535](https://github.com/DungTN22/Tower-defense/assets/161128678/bc0cf939-8957-4c0e-83ef-b2c4537e0c22)



-**Lưu ý:** game có 3 chế độ chơi, tốc độ của các zombie sẽ tăng dần theo mỗi cấp độ chơi

![Screenshot 2024-05-22 223959](https://github.com/DungTN22/Tower-defense/assets/161128678/8dd25ab7-16dd-47da-b28f-8c65b32ad846)


# Nguồn tham khảo
- Đồ họa [itch.io](https://itch.io/game-assets)
- Ngôn ngữ [c++/Mingw64](https://sourceforge.net/projects/mingw/)
- Âm thanh [sound](https://pixabay.com/vi/sound-effects/search/game/)
- Kiểu chữ [font](http://www.fontchu.com/games.htm)

# Các bước chạy game
- Tải Visual studio code,Codeblock ...
- Cài đặt SDL2, SDL_Mixer, SDL_Ttf, SDL_image.
- Mở chương trình và xây dựng chương trình.
- Cuối cùng hãy tận hưởng trò chơi.


# Lưu ý
Game được làm trên Visual Studio Code nên cách khởi chạy sẽ có đôi chút khác, nếu ai muốn chạy thử game trên Vscode hay copy 2 lệnh sau và lần lượt dán vào terminal:
- g++ -Isrc/Include/SDL2 -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer (có sẵn trong file Makefile)
- ./main
