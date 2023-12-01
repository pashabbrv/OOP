#include "levels.h"

Field& Levels::first_level(){
    Field* field = new Field;
    for(int x = 2; x < 5; x++){
        for(int y = 0; y < 4; y++)
            field->get_cell(x, y).set_access(false);
    }
    
    field->get_cell(1, 1).set_event(score->create());
    field->get_cell(1, 2).set_event(damage->create());
    field->get_cell(0, 3).set_event(place->create());
    return *field;
}

Field& Levels::second_level(){
    Field* field = new Field(10, 10);
    for(int x = 1; x < 9; x+=2){
        for(int y = 0; y < 10; y++)
            if(y != (9 - x))
                field->get_cell(x, y).set_access(false);
            else
                field->get_cell(x, y).set_event(score->create());
    }

    for(int y = 2; y < 10; y += 2)
        field->get_cell(9, y).set_event(damage->create());
    
    for(int y = 3; y < 7; y += 2)
        field->get_cell(8, y).set_event(score->create());
        
    field->get_cell(8, 7).set_event(place->create());
    return *field;
}