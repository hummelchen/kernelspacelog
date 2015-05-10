# Kernelspacelog - prototype of kernelspace keylogger for Linux systems

## Features:
 - runs as a kernel module
 - writes log to file

## Dependencies
 - C compiler GCC
 - linux-headers for your kernel 
 - linux-source for your kernel

## Build

Simply run `make`.

## Usage

After you run `make`, see file `keylogger.ko`. This application is the keylogger. It runs silently logging to the logfile specified at the compile time (option LOG_FILE_DIR). If this file already exist, new data would be appended.
To run this keylogger you should use `insmod keylogger.ko` and `rmmod keylogger.ko` to stop it. 

## Legal

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
