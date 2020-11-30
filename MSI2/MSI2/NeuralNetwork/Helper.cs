using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using MSI2;

namespace MSI2.NeuralNetwork
{
    class Helper
    {
        public static List<Point> PointsOfPaper(InkCanvas Paper)
        {
            List<Point> pointsOfPaper = new List<Point>();

            foreach (Stroke s in Paper.Strokes)
            {
                foreach (StylusPoint sp in s.StylusPoints)
                {
                    pointsOfPaper.Add(new Point(sp.X, sp.Y));
                }
            }
            return CenterTheTable(pointsOfPaper);
        }
        public static List<Point> CenterTheTable(List<Point> pointsOfPaper)
        {
            List<Point> CenterPointsOfPaper = new List<Point>();
            var mostLeftPoint = pointsOfPaper.Min(point => point.X);
            var mostTopPoint = pointsOfPaper.Min(point => point.Y);

            foreach (var point in pointsOfPaper)
            {
                CenterPointsOfPaper.Add(new Point(point.X - mostLeftPoint, point.Y - mostTopPoint));
            }
            return CenterPointsOfPaper;
        }

        public static int[,] Compression(int width, int height, int penWidht, int penHeight, List<Point> pointsOfPaper)
        {
            var table = new int[width, height];

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    table[x, y] = 0;
                }
            }

            var mostRightPoint = pointsOfPaper.Max(point => point.X);
            var mostBottomPoint = pointsOfPaper.Max(point => point.Y);

            foreach (var point in pointsOfPaper)
            {
                int StartX = (int)((double)((point.X - (penWidht / 2)) / mostRightPoint) * width);
                int EndX = (int)((double)((point.X + (penWidht / 2)) / mostRightPoint) * width);

                int StartY = (int)((double)((point.Y - (penHeight / 2)) / mostBottomPoint) * height);
                int EndY = (int)((double)((point.Y + (penHeight / 2)) / mostBottomPoint) * height);

                for (int x = StartX; x <= EndX; x++)
                {
                    for (int y = StartY; y <= EndY; y++)
                    {
                        if (x >= 0 && x < width)
                            if (y >= 0 && y < height) table[x, y] = 1;
                    }
                }
            }

            return table;
        }



        public static double[] Convert2dementionTo1(int[,] table, int width, int height, int resultWidht, int resultHeight)
        {
            var table2 = new int[resultWidht, resultHeight];

            for (int y = 0; y < resultHeight; y++)
            {
                for (int x = 0; x < resultWidht; x++)
                {
                    table2[x, y] = 0;
                }
            }

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    table2[x + ((resultWidht - width) / 2), y + ((resultHeight - height) / 2)] = table[x, y];
                }
            }

            double [] result = new double[resultWidht * resultHeight];

            int i = 0;

            for (int y = 0; y < resultHeight; y++)
            {
                for (int x = 0; x < resultWidht; x++)
                {
                    result[i++] = table2[x, y];
                }
            }
            return result;
        }
    }
}
