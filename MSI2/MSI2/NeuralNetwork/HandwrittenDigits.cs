using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MSI2.NeuralNetwork
{
    class HandwrittenDigits
    {
        NeuralNetwork network;

        public void Run()
        {
            MessageBox.Show("Creating neural network...");

            network = new NeuralNetwork(784, 400, 10, 0.025);
        }

        public void Train()
        {
            MessageBox.Show("Read treaning data...");

            var dataset = File.ReadAllLines(@"..\..\Source\TomaszW_train.txt");

            var allInputs = dataset
                .Select(x => x.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries)).ToArray();

            MessageBox.Show($"Training network with {allInputs.Length} samples...");

            var normalizedInputs = allInputs.Where(x => x.ToString() != "").Select(x => new
            {
                Answer = x[0],
                Inputs = NormalizeInput(x.Skip(1).ToArray())
            }).ToArray();

            var s = new Stopwatch();
            s.Start();

            foreach (var input in normalizedInputs)
            {
                var targets = Enumerable.Range(0, 10).Select(x => 0.0).Select(x => x + 0.01).ToArray();
                targets[int.Parse(input.Answer)] = 0.99;

                network.Train(input.Inputs, targets);
            }

            s.Stop();
            MessageBox.Show($"Training complete in {s.ElapsedMilliseconds}ms{Environment.NewLine}");
        }

        public void Train(double[] input, int target)
        {
            var s = new Stopwatch();
            s.Start();

            var targets = Enumerable.Range(0, 10).Select(x => 0.0).Select(x => x + 0.01).ToArray();
            targets[int.Parse(target.ToString())] = 0.99;
            network.Train(input, targets);

            s.Stop();
            MessageBox.Show($"Training complete in {s.ElapsedMilliseconds}ms{Environment.NewLine}");

            using (StreamWriter save = new StreamWriter(@"..\..\Source\TomaszW_train.txt", true))
            {
                StringBuilder output = new StringBuilder();
                output.Append(target + ",");

                foreach (var digit in input)
                {
                    output.Append(digit + ",");
                }
                save.Write(save.NewLine + output.ToString());
            }
        }

        public void SaveTest(double[] input, int target)
        {
            using (StreamWriter save = new StreamWriter(@"..\..\Source\TomaszW_test.txt", true))
            {
                StringBuilder output = new StringBuilder();
                output.Append(target + ",");

                foreach (var digit in input)
                {
                    output.Append(digit + ",");
                }
                save.Write(save.NewLine + output.ToString());
            }
            MessageBox.Show("Test was added");
        }

        public int CheckResult(double[] input)
        {
            var response = network.Query(input);
            var max = response.Max(x => x);
            var f = response.ToList().IndexOf(max);

            return f;
        }

        public void CheckNetwork()
        {
            Console.WriteLine("Querying network...");

            var queryDataset = File.ReadAllLines(@"..\..\Source\TomaszW_test.txt");

            var queryInputs = queryDataset
                .Select(x => x.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries)).ToArray();

            var scoreCard = new List<bool>();

            foreach (var input in queryInputs)
            {
                var normalizedInput = NormalizeInput(input.Skip(1).ToArray());
                var correctAnswer = int.Parse(input[0]);
                var response = network.Query(normalizedInput);

                var max = response.Max(x => x);
                var f = response.ToList().IndexOf(max);

                scoreCard.Add(correctAnswer == f);
            }

            MessageBox.Show($"Performed {scoreCard.Count} queries. Correct answers were {scoreCard.Count(x => x)}.");
            MessageBox.Show($"Network has a performance of {scoreCard.Count(x => x) / Convert.ToDouble(scoreCard.Count)}");
        }

        private static double[] NormalizeInput(string[] input)
        {
            return input
                .Select(double.Parse)
                .ToArray();
        }
    }
}
