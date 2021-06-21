package com.example.room_crud;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.room.Room;

import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    //UI
    private EditText name_text, update_name_text, update_id_text, delete_id_text;
    private TextView result_textView;
    private Button save, update, delete;

    //Room DB
    private UserDB userDB;

    private final String INSERT = "INSERT";
    private final String UPDATE = "UPDATE";
    private final String DELETE = "DELETE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //ui
        name_text = findViewById(R.id.name_text);
        update_name_text = findViewById(R.id.update_name_text);
        update_id_text = findViewById(R.id.update_id_text);
        delete_id_text = findViewById(R.id.delete_id_text);
        result_textView = findViewById(R.id.result_textView);
        save = findViewById(R.id.save_button);
        update = findViewById(R.id.update_button);
        delete = findViewById(R.id.delete_button);


        //db create
        userDB = Room.databaseBuilder(this, UserDB.class,"user_tables").build();

        //db list
        userDB.userDAO().getAll().observe(this, dataList -> {
            result_textView.setText(dataList.toString());
        });


        //db insert
        save.setOnClickListener(view -> {
            new DaoAsyncTask(userDB.userDAO(), INSERT, 0, "")
                    .execute(new User(name_text.getText().toString()));
        });

        //db update
        update.setOnClickListener(view -> {
            new DaoAsyncTask(userDB.userDAO(),UPDATE, Integer.parseInt(update_id_text.getText().toString()),
                    update_name_text.getText().toString()).execute();
        });


        //db delete
        delete.setOnClickListener(view -> {
            new DaoAsyncTask(userDB.userDAO(), DELETE, Integer.parseInt(delete_id_text.getText().toString()),
                    "").execute();
        });
    }

    private static class DaoAsyncTask extends AsyncTask<User, Void, Void>{
        private UserDAO userDAO;
        private String mType;
        private int mId;
        private String mName;

        private DaoAsyncTask(UserDAO userDAO, String type, int id, String name) {
            this.userDAO = userDAO;
            this.mType = type;
            this.mId = id;
            this.mName = name;
        }

        @Override
        protected Void doInBackground(User... users) {
            if(mType.equals("INSERT")){
                userDAO.insert(users[0]);
            }
            else if(mType.equals("UPDATE")){
                if(userDAO.getData(mId) != null){
                    userDAO.dataUpdate(mId,mName);
                }
            }
            else if(mType.equals("DELETE")){
                if(userDAO.getData(mId) != null){
                    userDAO.delete(userDAO.getData(mId));
                }
            }
            return null;
        }
    }



}