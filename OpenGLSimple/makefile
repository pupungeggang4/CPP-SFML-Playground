linux:
	clang++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lGL -std=c++17 -w

linuxbrew:
	clang++ main.cpp -o main -I /home/linuxbrew/.linuxbrew/include -L /home/linuxbrew/.linuxbrew/lib -rpath /home/linuxbrew/.linuxbrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lGL

macbrew:
	clang++ main.cpp glad/src/glad.c -o main -I glad/include -I /opt/homebrew/include -L /opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lGL -std=c++17 -w
