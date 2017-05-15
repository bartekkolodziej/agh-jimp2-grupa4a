//
// Created by bartek on 09.05.17.
//

#include "Serialization.h"

namespace academia {

    //Constructors:

    Room::Room(int id, std::string name,Type type){
        this->id = id;
        this->name = name;
        this->type = type;
    };


    Building::Building(int id, std::string name, std::initializer_list<Room> rooms){
        this->id = id;
        this->name = name;
        for(auto x: rooms) {
            std::reference_wrapper<const Serializable> room=std::cref<const Serializable>(x);
            this->rooms.push_back(room);
        }
    }

    BuildingRepository::BuildingRepository( std::initializer_list<Building> buildings){
        for(auto x: buildings) {
            std::reference_wrapper<const Serializable> building=std::cref<const Serializable>(x);
            this->buildings.push_back(building);
        }
    }

    // BuildingRepository functions:

    void BuildingRepository::Add(Building building){
        std::reference_wrapper<const Serializable> new_building=std::cref<const Serializable>(building);
        this->buildings.push_back(new_building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id){

        for(auto &building : buildings){
            if ((building.id == id)) return building;
        }

    }

    // Json Serialization:
    //1. Serializators:

    void BuildingRepository::StoreAll(JsonSerializer* serializer)const{

        (*serializer->output) << "{";
        serializer->ArrayField("buildings", buildings);
        (*serializer->output) << "]}";

    }

    void Room::Serialize(JsonSerializer *serializer) const {

        (*serializer->output)<<"{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->StringField("type",Type(type));
        (*serializer->output) << "}";

    }

    void Building::Serialize(JsonSerializer* serializer){
        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->ArrayField("rooms", rooms);
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

    // Not working whatever i do.
    //Can't access the content of the vector.
    //!!!

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

    //!!!

    //Xml Serialization:
    //1. Serializators:

    void Room::Serialize(XmlSerializer *serializer) const {

        serializer->Header("room");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->StringField("type", Type(type));
        serializer->Footer("room");

    }

    void Building::Serialize(XmlSerializer* serializer){
        serializer->Header("room");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->ArrayField("rooms", rooms);
        serializer->Footer("room");
    }

    void BuildingRepository::StoreAll(XmlSerializer* serializer)const{

        serializer->Header("building_repository");
        serializer->ArrayField("buildings", buildings);
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

    // Not working whatever i do.
    //Can't access the content of the vector.
    //!!!

    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {

        (*output)<< "<rooms>";
        for ( const Serializable &element:value) {

            element.Serialize(this);

        }
        (*output)<< "<\\rooms>";
    }

    //!!!

}