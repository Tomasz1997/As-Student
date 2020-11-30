package com.example.tasklist;

import androidx.appcompat.app.AppCompatActivity;

import android.content.res.ColorStateList;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.tasklist.TabLayout.TabItem;
import com.example.tasklist.TabLayout.TabManager;
import com.google.android.material.tabs.TabLayout;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {


    ArrayList<TabItem> tabList = new ArrayList<TabItem>();
    TabManager tabManager = new TabManager();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tabList.add( new TabItem( String.valueOf(getString(R.string.ShowTask)),  (Button) findViewById(R.id.ShowTask), (Button) findViewById(R.id.ShowTaskHide)) );
        tabList.add( new TabItem( String.valueOf(getString(R.string.AddTask)), (Button) findViewById(R.id.AddTask), (Button) findViewById(R.id.AddTaskHide)) );
        tabManager.setTabListOfItems(tabList);
    }

    public void onClickShowTask(View view) {

        tabManager.changeVisibilityOfTabByName( String.valueOf(getString(R.string.ShowTask)) );
    }

    public void onClickAddTask(View view) {
        tabManager.changeVisibilityOfTabByName( String.valueOf(getString(R.string.AddTask)) );
    }
}