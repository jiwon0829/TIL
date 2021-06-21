package com.example.room_crud;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;

import java.util.List;

@Dao
public interface UserDAO {
    @Query("SELECT * FROM User")
    LiveData<List<User>>getAll();

    @Query("SELECT * FROM User WHERE id = :mID")
    User getData(int mID);

    @Insert
    void insert(User user);

    @Delete
    void delete(User user);

    @Query("UPDATE User SET name = :mName WHERE id = :mId")
    void dataUpdate(int mId, String mName);

    @Query("DELETE FROM User")
    void clearAll();
}
