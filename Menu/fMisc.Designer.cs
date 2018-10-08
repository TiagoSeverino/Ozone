namespace Menu
{
    partial class fMisc
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fMisc));
            this.cbExitKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbRankReveal = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // cbExitKey
            // 
            this.cbExitKey.FormattingEnabled = true;
            this.cbExitKey.Location = new System.Drawing.Point(88, 39);
            this.cbExitKey.Name = "cbExitKey";
            this.cbExitKey.Size = new System.Drawing.Size(121, 21);
            this.cbExitKey.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Exit Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(70, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Rank Reveal";
            // 
            // cbRankReveal
            // 
            this.cbRankReveal.FormattingEnabled = true;
            this.cbRankReveal.Location = new System.Drawing.Point(88, 12);
            this.cbRankReveal.Name = "cbRankReveal";
            this.cbRankReveal.Size = new System.Drawing.Size(121, 21);
            this.cbRankReveal.TabIndex = 3;
            // 
            // fMisc
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(223, 74);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cbRankReveal);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbExitKey);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fMisc";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | Misc";
            this.Load += new System.EventHandler(this.fMisc_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ComboBox cbExitKey;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbRankReveal;
    }
}