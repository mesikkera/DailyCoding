using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace file_monitoring
{
	class Program
	{
		static void Main(string[] args)
		{
			string strDir = @"C:\";

			FileSystemWatcher monitor = new FileSystemWatcher();
			monitor.Path = strDir;
			monitor.IncludeSubdirectories = true;
			monitor.Filter = "*.txt";

			monitor.Created += new FileSystemEventHandler(onCreated);

			monitor.EnableRaisingEvents = true;

			Console.WriteLine(@"Start File Monitoring");
			Console.WriteLine(@" press 'q' to exit.");
			while(Console.Read() != 'q');
		}

		private static void onCreated(object source, FileSystemEventArgs e)
		{
			Console.WriteLine("File: " + e.FullPath + " " + e.ChangeType);
		}
	}
}