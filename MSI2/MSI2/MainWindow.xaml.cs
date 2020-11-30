using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MSI2.NeuralNetwork;

namespace MSI2
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        HandwrittenDigits network;

        public MainWindow()
        {
            InitializeComponent();

            network = new HandwrittenDigits();

            network.Run();

            network.Train();

            network.CheckNetwork();

            var pen = new DrawingAttributes();
            pen.Color = Colors.Chocolate;
            pen.Height = 25;
            pen.Width = 25;
            pen.FitToCurve = true;

            Paper.DefaultDrawingAttributes = pen;
        }

        private void BtnClearPaper_Click(object sender, RoutedEventArgs e)
        {
            Paper.Strokes.Clear();
            PaperResult.Text = "";
        }

        private void BtnDetectDigit_Click(object sender, RoutedEventArgs e)
        {
            PaperResult.FontSize = 300;
            PaperResult.Text = "";

            var points = Helper.PointsOfPaper(Paper);

            var table = Helper.Compression(20, 20, 25, 25, points);

            var table2 = Helper.Convert2dementionTo1(table, 20, 20, 28, 28);

            PaperResult.Text = network.CheckResult(table2).ToString();
        }

        private void BtnConvertToDigits_Click(object sender, RoutedEventArgs e)
        {
            PaperResult.FontSize = 12;
            PaperResult.Text = "";

            var points = Helper.PointsOfPaper(Paper);

            var table = Helper.Compression(20, 20, 25, 25, points);

            var table2 = Helper.Convert2dementionTo1(table, 20, 20, 28, 28);

            for (int i = 0; i < 28 * 28; i++)
            {
                if (i % 28 == 0) PaperResult.Inlines.Add(new LineBreak());

                PaperResult.Text += table2[i];
            }
        }

        private void BtnTrain_Click(object sender, RoutedEventArgs e)
        {
            var points = Helper.PointsOfPaper(Paper);

            var table = Helper.Compression(20, 20, 25, 25, points);

            var table2 = Helper.Convert2dementionTo1(table, 20, 20, 28, 28);

            network.Train(table2, Convert.ToInt32(TxtBoxDigitTrain.Text));
        }

        private void BtnSaveDigitToTest_Click(object sender, RoutedEventArgs e)
        {
            var points = Helper.PointsOfPaper(Paper);

            var table = Helper.Compression(20, 20, 25, 25, points);

            var table2 = Helper.Convert2dementionTo1(table, 20, 20, 28, 28);

            network.SaveTest(table2, Convert.ToInt32(TxtBoxSaveDigitToTest.Text));
        }
    }
}
