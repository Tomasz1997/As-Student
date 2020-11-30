package com.example.helloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity2 extends AppCompatActivity
{
    public EditText inputName;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        inputName = (EditText) findViewById(R.id.inputName);

        inputName.addTextChangedListener(new TextChangedListener<EditText>(inputName) {
            @Override
            public void onTextChanged(EditText target, Editable s) {
                TextView textViewWelcome = findViewById(R.id.welcome);
                String welcomePrompt = ForceManager.getWelcomePromptWithName( getString(R.string.welcome), String.valueOf(target.getText()) );
                textViewWelcome.setText(welcomePrompt);
            }
        });
    }
}