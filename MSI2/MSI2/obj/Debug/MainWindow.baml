   M S B A M L   `   `   `  ����?  ;MSI2, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:MSI2MSI2  5   	       MSI2.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   $localclr-namespace:MSI2     5   	     � Title$  
MainWindow��5   	   $	��500��6   $	��800��6)   .��5	      � 
������� � RowDefinitions 5
   
   �� 5      $	��50* �6   �� 5      $	��10* �6    � ColumnDefinitions 5   
   �� 5      $��1* �6   �� 5      $��1* �6   .+�5   
   �� -   5        $��Paper��5      $��0��6!   $��0��61    �� 
Background
 � ���$��20q�6R   �� 5   
   $��1��6   $��0��6!   
���i��$��20q�6E   ._�5      �� -   5        $��PaperResult��5      $�� ��6+   $	��300(�63   
��� ���$��Center=�6V   $��Center=�6s   5      �� 5   
   $��0��6   $��1��6%   $��2��62    �� Orientation$ 
Horizontal=�6F   .+�5      �� -   5        $��BtnClearPaper��5      $��Wyczyść kartkę��6*   
���i��$��40��6Z   $	��100��6f   $��Center=�6r   $��20 0 0 0q�6�   
�������6�   �� 5      -   5        $��BtnConvertToDigits��5      $��	Konvertuj��6/   
���i��$��40��6Z   $	��100��6f   $��Center=�6r   $��20 0 0 0q�6�   
�������6�   �� 5      -   5        $��BtnDetectDigit��5      $��Odczytaj cyfre��6+   
���i��$��40��6[   $	��100��6g   $��Center=�6s   $��20 0 0 0q�6�   
�������6�   �� 5      -   5        $��BtnTrain��5      $��Trenuj sieć��6%   
���i��$��40��6R   $	��100��6^   $��Center=�6j   $��20 0 0 0q�6�   
�������6�   �� 5      -   5        $��TxtBoxDigitTrain��5      
���i��
�������
���   �$��40��6m   $��20��6y   $��Center=�6�   $��0 0 0 0q�6�   �� 5      -   5        $��BtnSaveDigitToTest��5      $��Zpisz cyfre do testów��6/   
���i��$��40��6f   $	��130��6r   $��Center=�6~   $��20 0 0 0q�6�   
�������6�   �� 5      -	   5        $��TxtBoxSaveDigitToTest��5      
���i��
�������
���   �$��40��6r   $��20��6~   $��Center=�6�   $��0 0 0 0q�6�   5       5!      5"      