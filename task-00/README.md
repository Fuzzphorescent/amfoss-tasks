## Ubuntu Installation

+ Release: Ubuntu 22.04 LTS (Jammy Jellyfish)
+ Type: Dual-boot with Windows 10
+ Guide:[How to install Ubuntu 20.04](https://medium.com/linuxforeveryone/how-to-install-ubuntu-20-04-and-dual-boot-alongside-windows-10-323a85271a73)
+ Installation medium: Bootable USB

### Challenges faced:
#### Failure of balenaEtcher in creating a bootable USB  
After smashing three dishes and summoning the tech demons in candlelight, this issue was overcome by using Rufus instead.

#### Strategic partitioning of the hard disks 
As the SSD wasn't large enough to support both operating systems in their entirety comfortably, the root directory of Ubuntu was installed in the SSD while the home directory was loaded onto the HDD. This ensured that switching between the two OSs would be fast while saving the rest of the SSD storage for the bulkier software run on Windows.
