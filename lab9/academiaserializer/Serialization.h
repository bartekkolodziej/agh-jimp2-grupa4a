//
// Created by bartek on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>

namespace academia {

    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out){};

        ~Serializer(){};

        virtual void IntegerField(const std::string &field_name, int value) = 0;

        virtual void DoubleField(const std::string &field_name, double value)= 0;

        virtual void StringField(const std::string &field_name, const std::string &value)= 0;

        virtual void BooleanField(const std::string &field_name, bool value)= 0;

        virtual void SerializableField(const std::string &field_name, const Serializable &value)= 0;

        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const Serializable>> &value)= 0;

        virtual void Header(const std::string &object_name)= 0;

        virtual void Footer(const std::string &object_name)= 0;
        

    };


    class Serializable {
    public:
        virtual void Serialize(Serializer* serializer) = 0;

    };
    
    class JsonSerializer{
    public:
        JsonSerializer(std::stringstream* out){};
    };
    
    class XmlSerializer{
    public:
        XmlSerializer(std::stringstream* out){};
    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        
        std::string name;
        int id;
        Type type;

        std::string Type(Type type) {
            switch(type) {
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::CLASSROOM:
                    return "CLASSROOM";
                    
            }
        }

        void Serialize(Serializer* serializer){
            serializer->Header("Room");
            serializer->IntegerField("id: ", id);
            serializer->StringField("name: ",name);
            serializer->StringField("type: ", Type(type));
            serializer->Footer("Room");
        };

        void Serialize(JsonSerializer* serializer){};
        void Serialize(XmlSerializer* serializer){};
        
        Room(int id, std::string name,Type type){
            this->id = id;
            this->name = name;
            this->type = type;
        };
        Room(){};
    };

    class Building : public Serializable{
    public:
        std::string name;
        int id;
        std::vector<Room> rooms;
        

        void Serialize(JsonSerializer* serializer){};
        void Serialize(XmlSerializer* serializer){};
        
        Building(int id, std::string name, std::initializer_list<Room> rooms){
            this->id = id;
            this->name = name;
            for(auto x: rooms) this->rooms.push_back(x);
        };
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
