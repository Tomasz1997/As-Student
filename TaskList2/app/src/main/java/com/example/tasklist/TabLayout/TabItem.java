package com.example.tasklist.TabLayout;

import android.opengl.Visibility;
import android.view.View;
import android.widget.Button;

public class TabItem
{
    public String name;
    Button bShow;
    Button bHide;

    public TabItem(String name, Button show, Button hide)
    {
        this.name = name;
        this.bShow = show;
        this.bHide = hide;
    }

    public void setShow()
    {
        bShow.setVisibility(View.VISIBLE);
        bHide.setVisibility(View.GONE);
    }

    public void setHide()
    {
        bShow.setVisibility(View.GONE);
        bHide.setVisibility(View.VISIBLE);
    }

    public boolean isVisible()
    {
        if(bShow.getVisibility() == View.VISIBLE) return true;
        else return false;
    }

    public boolean isNullable()
    {
        if(name == null) return true;
        if(bShow == null) return true;
        if(bHide == null) return true;

        return false;
    }

    public boolean isPresent()
    {
        return ! this.isNullable();
    }
}
