package com.example.room_crud;

import androidx.annotation.NonNull;
import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity
public class User {
    @PrimaryKey(autoGenerate = true)
    private int id;
    private String name;

    public User(String name){
        this.name = name;
    }


    public void setId(int id){
        this.id = id;
    }
    public int getId(){
        return id;
    }


    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return name;
    }



    @NonNull
    @Override
    public String toString(){
        final StringBuffer sb = new StringBuffer("User {");
        sb.append("id= ").append(id);
        sb.append(", name=").append(name);
        sb.append('}').append('\n');
        return sb.toString();
    }

}
