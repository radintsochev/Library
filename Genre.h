#pragma once

enum Characteristic {
    FANTASY,
    THRILLER,
    CRIMINAL,
    MYSTERY,
    ROMANCE,
    SCIENCE_FICTION,
    HISTORICAL
};

enum Type {
    PROSE,
    POETRY,
    DRAMA,
    POEM
};

enum TargetAudience {
    KIDS,
    TEENS,
    ADULTS,
    ALL
};

class Genre {
private:
    size_t data = 0;

public:
    Genre();
    Genre(size_t number);

    void setCharacteristic(Characteristic characteristic);
    void setType(Type type);
    void setTargetAudience(TargetAudience audience);
    void toggleControl();
    bool validate();
    void display() const;
    friend bool operator==(const Genre& lhs, const Genre& rhs);
    friend bool operator!=(const Genre& lhs, const Genre& rhs);
};