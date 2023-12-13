all: lab clean

lab: player controller cell field damage score place levels game terminal handler render_terminal tracker main
	g++ player.o controller.o cell.o field.o damage.o score.o place.o levels.o game.o terminal.o handler.o render_terminal.o tracker.o main.o -o lab

main: main.cpp game.h terminal.h
	g++ -c main.cpp

player: player.cc player.h
	g++ -c player.cc

controller: controller.cc player.h ways.h controller.h cell.h field.h
	g++ -c controller.cc

cell: cell.cc cell.h event.h
	g++ -c cell.cc

field: field.cc cell.h player.h field.h
	g++ -c field.cc

damage: damage.cc damage.h event.h
	g++ -c damage.cc

score: score.cc score.h event.h
	g++ -c score.cc

place: place.cc place.h event.h
	g++ -c place.cc

levels: levels.cc levels.h field.h damage.h score.h place.h
	g++ -c levels.cc

game: game.cc game.h levels.h handler.h controller.h tracker.h render.h
	g++ -c game.cc

terminal: terminal.cc input.h terminal.h
	g++ -c terminal.cc

handler: handler.cc input.h operations.h
	g++ -c handler.cc

render_terminal: render_terminal.cc render_terminal.h damage.h score.h place.h render.h
	g++ -c render_terminal.cc

tracker: tracker.cc tracker.h render.h states.h
	g++ -c tracker.cc

clean:
	rm main.o player.o controller.o cell.o field.o damage.o score.o place.o levels.o game.o terminal.o handler.o render_terminal.o tracker.o