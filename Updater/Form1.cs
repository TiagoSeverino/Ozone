using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Compression;
using System.Net;

namespace Updater
{
    public partial class Form1 : Form
    {
        string key = @"C:\D0minator\key.txt";
        string version = "version.txt";
        string zipName = "d0minator.zip";

        string url = "http://api.d0minator.xyz/api/";

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            File.WriteAllText(key, textBox1.Text);

            WebRequest request = WebRequest.Create(url + "v");
            request.Credentials = CredentialCache.DefaultCredentials;
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            Stream dataStream = response.GetResponseStream();
            StreamReader reader = new StreamReader(dataStream);
            string responseFromServer = reader.ReadToEnd();

            reader.Close();
            dataStream.Close();
            response.Close();

            File.AppendAllText(version, "");
            string v = File.ReadAllText(version);

            if (v != responseFromServer)
            {
                try
                {
                    if (File.Exists(zipName))
                        File.Delete(zipName);

                    using (WebClient webClient = new WebClient())
                    {
                        webClient.UseDefaultCredentials = true;
                        webClient.DownloadFile(url + "download/" + textBox1.Text, zipName);
                    }

                    using (ZipArchive archive = ZipFile.OpenRead(zipName))
                    {
                        foreach (ZipArchiveEntry file in archive.Entries)
                        {
                            string completeFileName = Path.Combine(Directory.GetCurrentDirectory(), file.FullName);
                            if (file.Name == "")
                            {// Assuming Empty for Directory
                                Directory.CreateDirectory(Path.GetDirectoryName(completeFileName));
                                continue;
                            }
                            file.ExtractToFile(completeFileName, true);
                        }
                    }

                    if (File.Exists(zipName))
                        File.Delete(zipName);

                    MessageBox.Show("Successfully Updated!");
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Invalid Key!");
                }
            }
            else
            {
                MessageBox.Show("No Updates Available!");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            File.AppendAllText(key, "");
            textBox1.Text = File.ReadAllText(key);
        }
    }
}
