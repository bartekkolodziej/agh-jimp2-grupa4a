//
// Created by bartek on 09.05.17.
//

#include "Serialization.h"

namespace academia {

    Room::Room(int id, std::string name,Type type){
        this->id = id;
        this->name = name;
        this->type = type;
    };


    Building::Building(int id, std::string name, std::initializer_list<Room> rooms){
        this->id = id;
        this->name = name;
        for(auto x: rooms) this->rooms.push_back(x);
    }

    void Room::Serialize(JsonSerializer *serializer) const {

        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->StringField("type", Room::Type(type));
        (*serializer->output) << "}";

    }

    void Building::Serialize(JsonSerializer* serializer){
        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << "[";
        serializer->ArrayField("rooms", &rooms);
        (*serializer->output) << "]}";

    }

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
/*
    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value) {

        for (auto i : value) {

        }

        (*output) << "\"" << field_name << "\": ";
    }

*/
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
        serializer->StringField("rooms", &rooms);
        serializer->Footer("room");
    }

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

}