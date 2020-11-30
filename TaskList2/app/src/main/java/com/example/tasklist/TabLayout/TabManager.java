package com.example.tasklist.TabLayout;

import com.example.tasklist.TabLayout.TabItem;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class TabManager
{
    List<TabItem> tabItems;

    public TabManager(List<TabItem> tabItems)
    {
        this.tabItems = tabItems;
    }

    public TabManager()
    {
        this.tabItems = new ArrayList<TabItem>();
    }

    public void setTabListOfItems(List<TabItem> tabItems)
    {
        this.tabItems = tabItems;
    }

    private TabItem findTabByName(String name)
    {
        return tabItems.stream().filter(tab -> tab.name == name).findFirst().orElse(null);
    }

    private List<TabItem> findAllTabsWithout(TabItem tabItem)
    {
        return tabItems.stream().filter(tab -> tab.name != tabItem.name).collect(Collectors.toList());
    }

    public void showTabByName(String name)
    {
       TabItem tabItem = findTabByName(name);

       if(tabItem.isPresent()) tabItem.setShow();

       return;
    }

    public void showAllTabsWithout(TabItem tabItem)
    {
        for (TabItem tabToShow : findAllTabsWithout(tabItem))
        {
            tabToShow.setShow();
        }
    }

    public void hideTabByName(String name)
    {
        TabItem tabItem = findTabByName(name);

        if(tabItem.isPresent()) tabItem.setHide();

        return;
    }

    public void hideAllTabsWithout(TabItem tabItem)
    {
        for (TabItem tabToHide : findAllTabsWithout(tabItem))
        {
            tabToHide.setHide();
        }
    }

    public void changeVisibilityOfTabByName(String name)
    {
        TabItem tabItem = findTabByName(name);

        if(tabItem.isNullable()) return;

        if(tabItem.isVisible())
        {
            tabItem.setHide();

            showAllTabsWithout(tabItem);
        }
        else
        {
            tabItem.setShow();

            hideAllTabsWithout(tabItem);
        }
    }
}
