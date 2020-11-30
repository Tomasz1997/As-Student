package com.example.doradcazawodowy;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.TextView;

import java.sql.Array;
import java.util.List;
import java.util.stream.Collectors;

public class MainActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClickFindProfession(View view)
    {
        ErrorMessage errorMessage = new ErrorMessage(this);
        CareerManager careerManager = new CareerManager(this);

        if(careerManager.isAllOptionSelected() != true) errorMessage.show();
        else
        {
            errorMessage.hide();
            List<Career> careersSelectedForUser = careerManager.getCareersForUser();
            List<String> careersNamesForUser = careersSelectedForUser.stream().map(career -> career.name).collect(Collectors.toList());

            ListView listOfProfession = (ListView) findViewById(R.id.listOfProfession);
            ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, careersNamesForUser);
            listOfProfession.setAdapter(adapter);
        }
    }
}