#define RED   Color(255,0,0)
#define GREEN Color(0,255,0)
#define BLUE  Color(0,0,255)
#define BLACK Color(0,0,0)
#define WHITE Color(255,255,255)

#include "json.hpp"
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <string>
#include <memory>

#include "vec3.h"
#include "orthogonal_camera.h"
#include "perspective_camera.h"
#include "camera.h"
#include "sphere.h"
#include "primitive.h"
#include "primitive_list.h"
#include "material.h"


using json::JSON;
using namespace std;

typedef vec3 Color;
typedef vec3 Point;


//testando materiais
vector<Material*> g_materials;

void init_materials(){
    Material* red   = new Material(RED,   "red"  );
    Material* green = new Material(GREEN, "green");
    Material* blue  = new Material(BLUE,  "blue" );
    Material* black = new Material(BLACK, "black");
    Material* white = new Material(WHITE, "white");

    g_materials.push_back(red);
    g_materials.push_back(green);
    g_materials.push_back(blue);
    g_materials.push_back(black);
    g_materials.push_back(white);
}

string stringFromFile(string filename)
{
    //pega o arquivo e transforma em uma string pronta para ser convertida em objeto
    string aux;
    string userInput;
    ifstream infile;
    infile.open (filename);
        while(!infile.eof()){
            getline(infile,aux);
            userInput += aux;
        }
    infile.close();

    return userInput;
}

JSON parseFile(string filename){
    JSON obj;
    string userInput = stringFromFile(filename);
    obj = JSON::Load(userInput);
    return obj;
}

shared_ptr<Camera> cameraFromJSON(JSON obj){

    if (obj["camera"].IsNull()){
        std::cout<<"no instructions for camera in JSON file"<<std::endl;
        return nullptr;
    }else{
        string camParts[4] = {"origin","vertical","horizontal","corner"};
        vec3 aux[4];

        for(int i = 0; i < 4; i++){
            for(int j = 0;j < 3;j++){
                aux[i][j] = obj["camera"][camParts[i]][j].ToFloat();
            }
        }
        if(obj["camera"]["type"].ToString()=="orthogonal"){
            //warning for no direction instruction
            if (obj["camera"]["direction"].IsNull()){
                std::cout<<"no direction instruction for orthogonal camera"<<std::endl;
                return nullptr;
            }
            //warning for direction instruction without comma.
            float direction_input = obj["camera"]["direction"].ToFloat();
            if(direction_input == 0){
                std::cout<<"warning! direction read as 0, always write real numbers with commas"<<std::endl;
            }
            
            return make_shared<Orthogonal_camera>(aux[0],aux[1],aux[2],aux[3],direction_input);
        }else if(obj["camera"]["type"].ToString()=="perspective"){
            return make_shared<Perspective_camera>(aux[0],aux[1],aux[2],aux[3]);
        }else{
            std::cout<<"no instructions for camera type in JSON file"<<std::endl;
            return nullptr;
        }
    }
}

shared_ptr<Primitive_list> primitivesFromJSON(JSON obj){
    if (obj["primitives"].IsNull()){
        std::cout<<"no instructions for primitives in JSON file"<<std::endl;
        return nullptr;
    }else{


        int num_primitives = obj["primitives"].length();


        Primitive **list = new  Primitive*[num_primitives];

        Point aux;
        float radius;
        string materialAux;
        Material* material;


        for(int i =0; i < num_primitives; i++){

            aux[0] = obj["primitives"][i][0].ToInt();
            aux[1] = obj["primitives"][i][1].ToInt();
            aux[2] = obj["primitives"][i][2].ToInt();

            radius = obj["primitives"][i][3].ToFloat();

            materialAux = obj["primitives"][i][4].ToString();

            if(obj["primitives"][i][4].IsNull()){
                material->copy(*g_materials[3]);
            }else if(materialAux == "red"){
                material->copy(*g_materials[0]);
            }else if(materialAux == "blue"){
                material->copy(*g_materials[1]);
            }else if(materialAux == "green"){
                material->copy(*g_materials[2]);
            }else{
                material->copy(*g_materials[4]);
            }

            list[i] = new Sphere(aux, radius, *material);
        }

        return make_shared<Primitive_list>(list, num_primitives);
    }
}