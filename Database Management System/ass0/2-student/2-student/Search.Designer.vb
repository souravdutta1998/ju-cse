<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Search
    Inherits _2_student.Main

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label
        Me.rolltext1 = New System.Windows.Forms.TextBox
        Me.result1 = New System.Windows.Forms.Label
        Me.searchButton = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(38, 19)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(53, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter Roll"
        '
        'rolltext1
        '
        Me.rolltext1.Location = New System.Drawing.Point(118, 16)
        Me.rolltext1.Name = "rolltext1"
        Me.rolltext1.Size = New System.Drawing.Size(100, 20)
        Me.rolltext1.TabIndex = 1
        '
        'result1
        '
        Me.result1.AutoSize = True
        Me.result1.Location = New System.Drawing.Point(91, 90)
        Me.result1.Name = "result1"
        Me.result1.Size = New System.Drawing.Size(0, 13)
        Me.result1.TabIndex = 2
        '
        'searchButton
        '
        Me.searchButton.Location = New System.Drawing.Point(107, 43)
        Me.searchButton.Name = "searchButton"
        Me.searchButton.Size = New System.Drawing.Size(75, 23)
        Me.searchButton.TabIndex = 3
        Me.searchButton.Text = "SEARCH"
        Me.searchButton.UseVisualStyleBackColor = True
        '
        'Search
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.searchButton)
        Me.Controls.Add(Me.result1)
        Me.Controls.Add(Me.rolltext1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Search"
        Me.Text = "Search"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents rolltext1 As System.Windows.Forms.TextBox
    Friend WithEvents result1 As System.Windows.Forms.Label
    Friend WithEvents searchButton As System.Windows.Forms.Button
End Class
