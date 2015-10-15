using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.NetworkInformation;
using System.Management;

namespace GetHardWareInfo
{
	class Program
	{
		static void Main(string[] args)
		{
			string strMacresult = GetMac ();
			Console.WriteLine ("Physical MAC Address is: " + strMacresult + "");
			Console.ReadLine ();
		}

		// Get Physical MAC Address
		static public string GetMac()
		{
			string strMac = "";

			NetworkInterface[] nics = NetworkInterface.GetAllNetworkInterfaces ();
			foreach (NetworkInterface nic in nics) {
				PhysicalAddress pa = nic.GetPhysicalAddress ();
				if (pa != null) {
					strMac = pa.ToString;
					break;
				}
			}
		}
	}
}

