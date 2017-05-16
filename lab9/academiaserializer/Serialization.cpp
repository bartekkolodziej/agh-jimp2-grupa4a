//
// Created by bartek on 09.05.17.
//

#include "Serialization.h"

namespace academia {

    std::vector <std::reference_wrapper<const Serializable>>RoomsToReferenceWrapper( std::vector<Room> array){

        std::vector <std::reference_wrapper<const Serializable>> return_array;
        for(std::vector<Room>::iterator element = array.begin(); element != array.end(); ++element) {
            return_array.emplace_back(std::cref<const Serializable>(*element));
        }
        return return_array;
    }

    std::vector <std::reference_wrapper<const Serializable>>BuildingsToReferenceWrapper( std::vector<Building> array){

        std::vector <std::reference_wrapper<const Serializable>> return_array;
        for(std::vector<Building>::iterator element = array.begin(); element != array.end(); ++element) {
            return_array.emplace_back(std::cref<const Serializable>(*element));
        }
        return return_array;
    }



    //Constructors:

    Room::Room(int id, std::string name,Type type){
        this->id = id;
        this->name = name;
        this->type = type;
    };


    Building::Building(int id, std::string name, std::initializer_list<Room> rooms) {
        this->id = id;
        this->name = name;
        this->rooms = rooms;
        /*
        for (auto room: rooms) {
            this->rooms.push_back(room);
        }
        */
    }



    //ERROR!

    BuildingRepository::BuildingRepository( std::initializer_list<Building> buildings){
        this->buildings=buildings;
        /*
        for (Building building : buildings) {
            this->buildings.push_back(building);
        }
        */
    }

    // BuildingRepository functions:

    void BuildingRepository::Add(const Building &building){
        this->buildings.emplace_back(building);
    }

    //ERROR!



    std::experimental::optional<Building> BuildingRepository::operator[](int id){

        std::experimental::optional<Building> new_building;
        for(std::vector<Building>::iterator building = buildings.begin(); building != buildings.end(); ++building) {
            if (building->id== id) {
                new_building.emplace(*building);
                return new_building;
            }
        }

    }


    // Json Serialization:
    //1. Serializators:

    void BuildingRepository::StoreAll(JsonSerializer* serializer)const{

        (*serializer->output) << "{";
        serializer->ArrayField("buildings", BuildingsToReferenceWrapper(buildings));
        (*serializer->output) << "]}";

    }

    void Room::Serialize(JsonSerializer *serializer) const {

        (*serializer->output)<<"{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->StringField("type",ReturnTypeString(type));
        (*serializer->output) << "}";

    }

    void Building::Serialize(JsonSerializer* serializer)const{
        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->ArrayField("rooms", RoomsToReferenceWrapper(rooms));
        (*serializer->output) << "}";
    }

    //2. Functions:

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*output) << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        JsonSerializer serializer(output);
        value.Serialize(&serializer);
    }

    void JsonSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {

        bool IsFirst = true;
        (*output) << "\"" <<  field_name << "\": [";

        for ( const Serializable &element:value) {

            if(!IsFirst)(*output)<< ", ";
            else IsFirst = false;
            element.Serialize(this);

        }
        (*output) << "]";
    }

    //Xml Serialization:
    //1. Serializators:

    void Room::Serialize(XmlSerializer *serializer) const {

        serializer->Header("room");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->StringField("type", ReturnTypeString(type));
        serializer->Footer("room");

    }

    void Building::Serialize(XmlSerializer* serializer)const{
        serializer->Header("room");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->ArrayField("rooms", RoomsToReferenceWrapper(rooms));
        serializer->Footer("room");
    }

    void BuildingRepository::StoreAll(XmlSerializer* serializer)const{

        serializer->Header("building_repository");
        serializer->ArrayField("buildings", BuildingsToReferenceWrapper(buildings));
        serializer->Footer("\\building_repository");

    }


     //2. Functions:

    void XmlSerializer::Header(const std::string &object_name){
        (*output) << "<" <<object_name << "\\>";
    }

    void XmlSerializer::Footer(const std::string &object_name){
        (*output) << "<" <<object_name << "\\>";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*output) << "<" << field_name << ">" <<value<< "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        XmlSerializer serializer(output);
        value.Serialize(&serializer);
    }


    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {

        (*output) << "<" << field_name << ">";
        for ( const Serializable &element:value) {

            element.Serialize(this);

        }
        (*output) << "<" << field_name << "\\>";
    }


}